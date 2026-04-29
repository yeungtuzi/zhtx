//	skill.c
//
// 	This is the standard skill daemon object. All objects defining a skill
//	should inherit this as its skeleton.

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg)
{
	string func, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		func = arg;
		target_ob = me;
	}

	if( !stringp(file = (string)this_object()->exert_function_file(func))
	||	file_size(file + ".c") <= 0 )
		return 0;

	if ( func == "lifeheal") {

          if((int)target_ob->query("eff_kee") > (int)target_ob->query("max_kee")*9/10)
                return notify_fail( target_ob->name() +
                        "看起来很正常，并没有受伤。\n" );

	}

	return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg)
{
	string action, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		action = arg;
	}

	if( !stringp(file = (string)this_object()->perform_action_file(action))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "perform", me, target_ob);
}

int cast_spell(object me, string spell, object target)
{
	string file;

	notify_fail("你所选用的咒文系中没有这种咒文。\n");

	if( !stringp(file = (string)this_object()->cast_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "cast", me, target);
}

int conjure_magic(object me, string spell, object target)
{
	string file;

	notify_fail("你所选用的法术系中没有这种法术。\n");

	if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "conjure", me, target);
}

int scribe_spell(object me, object ob, string spell)
{
	string file;

	if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "scribe", me, ob );
}

// added from xkx cmy 971018
// The following two functions are used to modify the random function
// for shaolin wugong.

int sum(int n,int base,int d)
{
  return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{
  int i = 1;
  int randnum = random(sum(n,base,d));

  if (sum(6,base,d) < randnum)
   {
    i = 7;
    while (sum(i,base,d) < randnum)
          i++;
    }
  else {
    while (sum(i,base,d) < randnum)
        i++;
   }
  return (i-1);
}

mapping enable_req(object ob) { return ([ ]); }
mapping level_req(int level,object ob) { return ([ ]); }
string skill_name() { return "";}
int check_base_skill(object me,string skillname)
{
	mapping all_skill_map,restrict;
	int i;
	string* base_skill;
	
	restrict = level_req(me->query_skill(skillname,1),me);
	if(sizeof(restrict) == 0 ) return 1;
	all_skill_map = me->query_skills();
	base_skill = keys(restrict);
	for(i=0;i<sizeof(restrict);i++) {
		if( (int)all_skill_map[base_skill[i]] >= (int) restrict[base_skill[i]])
				continue;	
		else {
		write("你的"+to_chinese(base_skill[i])+"火候不够，不能学习或使用"+skillname+"！\n");
		return 0;
	   }
	}
	return 1;
}
int valid_use( object me,string skillname) {
	mapping all_skill_map,restrict;
	int i;
	string* base_skill;
	string chn_skillname;
	if(skillname) {
		chn_skillname = to_chinese(skillname);
	}
	else {
		chn_skillname="这项武功";
	}

	restrict = enable_req(me);
	if(sizeof(restrict) == 0 ) return 1;
	all_skill_map = me->query_skill_map();
	if(!all_skill_map) {
		write("你没有相应的武功配合，不能使用"+chn_skillname+"\n");
		return 0;
	}
	base_skill = keys(restrict);
	for(i=0;i<sizeof(restrict);i++) {
	//by yeung to add surpport for 小无相功
	   if( all_skill_map[base_skill[i]] == (string) restrict[base_skill[i]] || (base_skill[i]=="force" && all_skill_map[base_skill[i]]=="xiaowuxiang-gong") ) 
		continue;
	   else {
		write(chn_skillname+"必须配合"+to_chinese(restrict[base_skill[i]])+"才能使用！\n");
		return 0;
	   }	
	}
	return  check_base_skill(me,skillname);
}

