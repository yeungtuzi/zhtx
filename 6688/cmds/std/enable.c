// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

void check_unsurpported_skill(object me);
void check_related(object me,string ski,string map_to);
void check_ally(object me);

mapping valid_types = ([
	"axe"	: 	"斧法",
        "dugong":      "毒功",
        "unarmed":      "拳脚",
        "sword":        "剑法",
        "blade":        "刀法",
        "hook":         "钩法",
        "hammer":       "锤法",
        "spear":        "枪法",
        "halberd":      "戟法",
        "fork":         "叉法",
        "stick":        "棍法",
        "club":         "棍法",
        "staff":        "杖法",
        "throwing":     "暗器",
        "force":        "内功",
        "parry":        "招架",
        "dodge":        "轻功",
        "magic":        "法术",
        "spells":       "咒文",
        "move":         "行动",
        "array":        "阵法",
        "whip":         "鞭法",
        "finger":       "指法",
        "hand":         "手法",
        "cuff":         "拳法",
        "claw":         "爪法",
        "strike":       "掌法",
        "iron-cloth":   "铁布衫",
]);

int main(object me, string arg)
{
        mapping map;
        string *types, *skill, ski, map_to;
        int i, modify;

        seteuid(getuid());

        if( !arg ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("你现在没有使用任何特殊技能。\n");

                skill = keys(valid_types);
                write("以下是你目前使用中的特殊技能。\n");
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        printf("  %-20s： %-20s  有效等级：%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "无" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                return 1;
        }

        if( arg=="?" ) {
                write("以下是可以使用特殊技能的种类：\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }

        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("指令格式：enable [<技能种类> <技能名称>|none]\n");

        if( undefinedp(valid_types[ski]) )
                return notify_fail("没有这个技能种类，用 enable ? 可以查看有哪些种类。\n");

        if( map_to=="none" ) {
                check_related(me,ski,0);
                me->map_skill(ski);
                me->reset_action();
                write("Ok.\n");
                return 1;
        } else if( map_to==ski ) {
                write("「" + to_chinese(ski) + "」是所有" + valid_types[ski] + "的基础，不需要 enable。\n");
                return 1;
        }

        if( !me->query_skill(map_to, 1) )
                return notify_fail("你不会这种技能。\n");

//      if( !me->query_skill(ski, 1) )
//              return notify_fail("你连「" + to_chinese(ski) + "」都没学会，更别提"
//                      + to_chinese(map_to) + "了。\n");

        // some skills only for npc
        if( SKILL_D(map_to)->npc_only()) {
                return notify_fail("你不能使用这种技能\n");
        }

        if( !SKILL_D(map_to)->valid_enable(ski,map_to) )
                return notify_fail("这个技能不能当成这种用途。\n");
        // check if valid_use ; dao

        if( me->query_skill_mapped("force")!="xiaowuxiang-gong" && !SKILL_D(map_to)->valid_use(me) ) {
                return notify_fail("你现在不能使用这个技能\n");
// check if force type is same 
        } else if ( ski == "force" ) {
                string my_type ,s_type;
                my_type = me->query("force_type");
                s_type = SKILL_D(map_to)->query_force_type();
                if( my_type ) { 
                   if( my_type != s_type ) {
                        if ( me->query("max_force") > 10 ) {
                           notify_fail("你现在的内功基础与"+to_chinese(map_to)+"性质不符，无法改练这种内功。\n");
                        }
                        else {
                           notify_fail("你要改变内功类型必须放弃现有的内功，如果你下定决心了请用散功(sangong)命令。\n"); 
                        }
                        return 0;
                   }
                } 
                else {
                        me->set("force_type",s_type);
                }

        }
        check_related(me,ski,map_to);
        me->map_skill(ski, map_to);
        me->reset_action();
        write("Ok.\n");
        
        if( ski=="magic" ) {
                write("你改用另一种法术系，灵力必须重新修炼。\n");
                me->set("atman", 0);
                me->set("atman_factor",0);
                me->receive_damage("gin", 0);
        } else if( ski=="force" ) {
                write("你改用另一种内功\，内力必须重新修炼。\n");
                me->set("force", 0);
//                me->set("force_factor",0);为了yunhai-force能和jiuyang切换 by masterall
                me->receive_damage("kee", 0);
        } else if( ski=="spells" ) {
                write("你改用另一种咒文系，法力必须重新修炼。\n");
                me->set("mana", 0);
                me->set("mana_factor",0);
                me->receive_damage("sen", 0);
        }

	check_unsurpported_skill(me);
    	check_ally(me);
        return 1;
}

void check_related(object me,string ski,string map_to) {
        mapping map_skill,req_map;   
        // 2026-04-30: unused variable commented out
        // mapping req;
        int i,j;
        string* base_skill,*req_base;
        string orig_map_to; 
        map_skill =  me->query_skill_map();
        
	//小无相功
	if( me->query_skill_mapped("force") == "xiaowuxiang-gong" &&
		map_to != "magic" && map_to !="spells" ) return;

      if(!map_skill) return ;
        orig_map_to = map_skill[ski];
//      write("abcd:"+ski+orig_map_to);
        if( !orig_map_to || orig_map_to == map_to  ) return;
        base_skill = keys(map_skill);
        for(i=0;i<sizeof(base_skill);i++) {
        //      write("checking"+ map_skill[base_skill[i]]+"\n");
                if(base_skill[i] == ski) continue;
                req_map = (SKILL_D(map_skill[base_skill[i]])->enable_req(me));
                req_base = keys(req_map);
                for(j=0;j<sizeof(req_map);j++) {
                   if(req_map[req_base[j]] == orig_map_to) {
        //              write("find relate"+to_chinese(map_skill[base_skill[i]])+"\n");
                        write("你放弃使用"+to_chinese(map_skill[base_skill[i]])+"\n");
                        me->map_skill(base_skill[i]);
                        };
                }
        }      

}

//卸下所有不支持的功夫
void check_unsurpported_skill(object me)
{
	mapping map_skill,req_map;
	string en_skill;
        string *base_skill,*req_base;
	int i,j,flag;

         if(wiz_level(me)) return;

        //小无相功
        if( me->query_skill_mapped("force") == "xiaowuxiang-gong" ) return;

        map_skill =  me->query_skill_map();
        base_skill = keys(map_skill);
	for(i=0;i<sizeof(base_skill);i++)
	{
		en_skill = map_skill[base_skill[i]];
	        req_map = (SKILL_D(en_skill)->enable_req(me));		
		req_base = keys(req_map);
//		if( !sizeof(req_map) ) continue;
		flag = 0;
		for(j=0;j<sizeof(req_map);j++)
		{
			if( req_map[req_base[j]] != me->query_skill_mapped(req_base[j]) )
			{
				flag = 1;
			}
		}
		if( flag )
		{
			me->map_skill(base_skill[i]);
	                write(to_chinese(en_skill)+"缺乏必要支持，放弃使用。\n");
		}
	}

}

void check_ally(object ob)
{
	object *obj;
	int coeff;

	//tell_object(ob,"checking your ally message...\n");
       	if(obj=ob->query_temp("ally/partner"))
	{

		if( (coeff = "/cmds/std/allyhit"->check_valid_ally(ob)) < 10 )
		{
	
        	        int i;

                	ob->delete_temp("ally");

                	i=sizeof(obj);
                	while(i--)
                	{
                        	if(objectp(obj[i]))
                        	{
                                	obj[i]->delete_temp("ally");
                     			obj[i]->start_busy(2);
				}
  		        }
			ob->start_busy(2);
                	message_vision(HIW "因为武功无法相互配合，联合攻击终止。\n" NOR,ob);
        	}
	}
}



int help(object me)
{
        write(@HELP
指令格式 : enable [<技能种类> <技能名称> | none]
           enable ?

这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个 ? 会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
