#include <combat.h>
#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
	"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
        "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
        "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
        "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});


string *move_attack_msg = ({
	"$N双肘略沉，左手一引，$n的攻势不由自主地被移向了$k\n!",
	"$N一声轻笑，顺手将$k牵引过来，挡住了$n的这一招。\n",
	"$N双臂一振，强劲无伦的真气在身周形成了一道道气旋，卷着$k迎向$n的凌厉攻势！\n",
	"$n一招攻出，立时便知不妙，果然$n哇哇大叫声中，这一招中途变向，重重击向$k！\n",
	});

int valid_enable(string usage) { return (usage == "parry"); }

int valid_learn(object me) 
{
	string filestring,master_id;
	
	filestring = read_file("/d/mingjiao/master.dat");
/*
	if( stringp(filestring) )
           sscanf(filestring,"Master_ID = %s\nlast_synod_time",master_id);//	write("Master ID is "+master_id+"\n");
	if( !master_id || master_id != me->query("id") )
		return notify_fail("你不是掌教弟子，不能修习乾坤大挪移\n");

*/
	if( me->query("max_force") < me->query_skill("qiankun-danuoyi",1)*8)
		return notify_fail("你的内力不足，无法学习乾坤大挪移\n");
	return 1; 
}

string query_parry_msg(object weapon,object defenser,object attacker,mapping attack_action)
{
	object *targets,target,me,victim;
	mapping his_action;
	int	i,level;
	string  msg;

	me = defenser;
	victim = attacker;
	his_action = attack_action;

	level = me->query_skill("qiankun-danuoyi",1);
	target = me->select_opponent();
	if( !objectp(target) )
		target = victim;	
        if( ( level>240 || (his_action["unparryable"] < 10 && random(level/4) > random(target->query_cps()))) && me->query("force") > 200 && !me->is_busy()) 
	{
//		message("system","Controler:"+me->query("name")+"\nAttacker:"+victim->query("name")+"\nDefenser:"+target->query("name") + "\n",users());
		msg = move_attack_msg[random(sizeof(move_attack_msg))];
		message_vision(msg,me,victim,target);
		me->add("force",-50);
		COMBAT_D->do_attack(victim,target,victim->query_temp("weapon"),TYPE_SELFATTACK,his_action,me);
		return "";
	}
        return parry_msg[random(sizeof(parry_msg))];
}
mapping enable_req() {
	return( ([ 
		"force":"jiuyang-shengong",	
	]) );
}

int practice_skill(object me)
{
        return notify_fail("乾坤大挪移不能练。\n");
}
void skill_improved(object me)
{
        int s;

        s = me->query_skill("qiankun-danuoyi",1);
          if((int)me->query("bln") > 50 ) return 0;
        if((int)me->query("bln") < s/4) {
                tell_object(me, HIW "由於你勤奋修习乾坤大挪移，你的平

衡能力提高了。\n" NOR);
                me->add("bln", 1);
        }
}

int query_faith_req(int skill) {
	return 100+skill*18;

}

int effective_level() {
	if( this_player()->query_skill("qiankun-danuoyi",1) > 240 )
		return 20;
        return 12;
}
