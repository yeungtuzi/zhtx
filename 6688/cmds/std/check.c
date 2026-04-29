 // check.c

#include <ansi.h>

inherit F_CLEAN_UP;
string *skill_level_desc = ({

	BLU "初学乍练" NOR,
	HIB "不知所以" NOR,
	HIB "粗通皮毛" NOR,
	HIB "略识之无" NOR,
	HIB "渐有所悟" NOR,
	HIB "半生不熟" NOR,
	HIB "马马虎虎" NOR,
	RED "平淡无奇" NOR,
	RED "平平常常" NOR,
	RED "触类旁通" NOR,
	
	RED "已有小成" NOR,
	YEL "心领神会" NOR,
        YEL "深入浅出" NOR,
        YEL "挥洒自如" NOR,
        YEL "驾轻就熟" NOR,
        HIC "出类拔萃" NOR,           
        HIC "初入佳境" NOR,
        HIC "神乎其技" NOR,
        HIC "威不可当" NOR,
        HIC "出神入化" NOR,
        
        HIY "略有大成" NOR,
        HIY "已有大成" NOR,
        HIY "豁然贯通" NOR,
        HIY "超群绝伦" NOR,
        CYN "登峰造极" NOR,
        CYN "旷古绝伦" NOR,
        CYN "卓然大家" NOR,
        CYN "一代宗师" NOR,
        HIG "独步天下" NOR,
        HIG "冠绝当代" NOR,
        
        HIG "无可匹敌" NOR,
        HIG "所向披靡" NOR,
        HIM "空前绝后" NOR,
        HIM "登堂入室" NOR,
        HIM "惊世骇俗" NOR,
        HIM "超凡入圣" NOR,
        HIW "震古烁今" NOR,
        HIW "深藏不露" NOR,
        HIW "返璞归真" NOR,
        HIW "深不可测" NOR,

});

string *knowledge_level_desc = ({

	BLU "新学乍用" NOR,
	HIB "不甚了了" NOR,
	HIB "不知端倪" NOR,
	HIB "平淡无奇" NOR,
	HIB "司空见惯" NOR,
	HIB "初窥门径" NOR,
	HIB "略知一二" NOR,
	RED "茅塞顿开" NOR,
	RED "略识之无" NOR,
	RED "滚瓜烂熟" NOR,
	
	YEL "马马虎虎" NOR,
	YEL "轻车熟路" NOR,
	YEL "运用自如" NOR,
	YEL "触类旁通" NOR,
	HIC "深入浅出" NOR,
	HIC "已有小成" NOR,
	HIC "心领神会" NOR,
	HIC "豁然开朗" NOR
	HIC "了然于胸" NOR,
	HIC "挥洒自如" NOR,
	
	HIC "独具匠心" NOR,
    	HIY "见多识广" NOR,
	HIY "无所不通" NOR,
	HIY "无与伦比" NOR,
	HIY "卓尔不群" NOR,
	HIY "满腹经纶" NOR,
	CYN "学富五车" NOR,
	CYN "豁然贯通" NOR,
	CYN "包罗万象" NOR,
	CYN "博古通今" NOR,
	
	HIG "醍醐灌顶" NOR,
	HIG "一代宗师" NOR,
	HIG "博大精深" NOR,
	HIG "超群绝伦" NOR,
	HIG "登峰造极" NOR,
	HIM "举世无双" NOR,
	HIM "独步天下" NOR,
	HIW "震古铄今" NOR,
	HIW "超凡入圣" NOR,
	HIW "深不可测" NOR,
});
string skill_level(string, int,string);
int Random_Level(int lvl);
private void complete_check(object me, object victim, object ob, int cp, int dp);

int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        int cp,dp;
        
        if( me->is_busy() ) return notify_fail("你现在没有空！\n");

        if( me->query_temp("checking") )
                return notify_fail("你已经在找机会下手了！\n");
        if( me->query("sen") < 60)
                return notify_fail("你的精神不够集中！\n");

        if( !arg || sscanf(arg, "%s",who)!=1 ) 
                return notify_fail("指令格式：check <人物>\n");

        victim = present(who, environment(me));
        
        if (!victim) victim = find_player(arg);
        
        if (!victim) victim = find_living(arg);
        
        if( !victim ) 
                return notify_fail("你想查看的对象不在这里。\n");
        if( victim == me)
                return notify_fail("需要这么麻烦么?打一下skills不就知道了?\n");

        if((string)me->query("family/master_id")==(string)victim->query("id"))
                return notify_fail("那就是你师傅，何必多此一举。\n"); 

        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("玩家不能查看巫师。\n");
        
        cp = (int)me->query_skill("checking",1) * 5 + (int)me->query("kar") * 20;
        cp += me->query_int() * 5 + me->query_elo() * 20;
        cp /= 2;
         // by YEUNG , 让口才的天赋发挥作用
          cp += me->query_elo()*50;
        
        if( cp < 1 ) cp = 1;
        
        if(me->is_fighting()) 
        {
                cp /= 2;
                me->start_busy(3);
        }
        
        dp = (int)victim->query_skill("checking",1) * 3+(int)victim->query("sen");
        
        if( victim->is_fighting() ) dp /= 10;
    	//printf("cp = %d,dp = %d\n",cp,dp);
        write("你满脸堆笑，想靠近" + victim->name() + "，打探点什么消息 ...\n\n");

        me->set_temp("checking", 1);
        me->receive_damage("sen",random(60));
	call_out("complete_check", 3, me, victim, ob, cp, dp);
	return 1;
}

private void complete_check(object me, object victim, object ob, int cp, int dp)
{
        mapping vic,skl,lrn,map,quest;

        string *sname, *mapped;
        string lvl_str1,lvl_str2;
        int i,rl;

	me->delete_temp("checking");
        rl = Random_Level((int)me->query_skill("checking",1));
       
	

	if( environment(victim) != environment(me) ) 
        {
                tell_object(me, "太可惜了，你想打探的目标已经走了。\n");
                me->delete_temp("checking");
                return;
				
        }
        if (!living(victim))
                {
                   tell_object(me,"真可惜，你想打探的对象已经死了。\n");
                   me->delete_temp("checking");
                   return;	
				   
                } 
	   //printf("cp = %d,dp = %d\n",cp,dp);
       if( living(victim) 
        && random(cp+dp) > dp ) 
        {
	 
                tell_object(me, HIW "成功了！\n" NOR);
                tell_object(me, "你成功地打探到" + victim->name() + "的一点消息！\n");

                me->improve_skill("checking", random(me->query("int")));
		skl = victim->query_skills();
                if(!sizeof(skl)) 
                {
			write( ( victim->name()) + "目前并没有学会任何技能。\n");
                 	 if( interactive(me) && (quest = me->query("quest"))
	        	&& ( (int)me->query("task_time") >= time())
 	 	        && (victim->name() == quest["quest"])
 	 		&& (quest["quest_type"] == "打探")
 	 		&& !userp(victim)
 	 		&& (!me->query("over_time")))
			   {
					me->set("over_time", time());
			    }
	 				return ;
          		}
          	      	 if(rl<2)
        	 if( interactive(me) && (quest = me->query("quest"))
	 	&& ( (int)me->query("task_time") >= time())
 	 	&& (victim->name() == quest["quest"])
 	 	&& (quest["quest_type"] == "打探")
 	 	&& !userp(victim)
 	 	&& (!me->query("over_time")))
 	 	{
		        me->set("over_time", time());
		 }
         
       	
          		//write( (victim->name()) +"目前所学过的技能：\n\n");
				sname  = sort_array( keys(skl), (: strcmp :) );
				map = victim->query_skill_map();
				if( mapp(map) ) mapped = values(map);
        		if( !mapped ) mapped = ({});
	                lrn = victim->query_learned();
		    	if( !mapp(lrn) ) lrn = ([]);
				i = random(sizeof(skl));
				{
				lvl_str1 = skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]-rl*5,sname[i]); 
				lvl_str2 = skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]+rl*5,sname[i]);
				if(lvl_str1==lvl_str2)
				/*
					printf("%s%s%-40s" NOR " - %-10s\n", 
					(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
					(member_array(sname[i], mapped)==-1? "  ": "□"),
					to_chinese(sname[i]) + " (" + sname[i] + ")",
                    			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]],sname[i]),
					);
				 */
				 	printf("听说%s的%s这项功夫是达到了%s的境界。\n",
				 		victim->name(),to_chinese(sname[i]),
				 		lvl_str1,
				 		);
				 else 
				 	{
				 		printf("听说%s的%s这项功夫处于%s和%s之间的境界。\n",
				 			victim->name(),to_chinese(sname[i]),
				 			lvl_str1,lvl_str2,		 		
				 			);	
				 	}	
				}
         	write("\n");
	        me->delete_temp("checking");
	        me->start_busy(5);
		return;
        }
	    else
        {
                if( random(cp) > dp/2 )
				{
				        message_vision(victim->name() + "狠狠地瞪了$N一眼，喝道：滚！ $N吓了一跳，急忙扭头灰溜溜地走开了。\n", me);
					me->delete_temp("checking");
					return;
                }

                tell_object(me, victim->name() + "扭过头去，对你理都不理。\n");
                tell_object(victim, "你扭过头去，对" + me->name() + "理都不理。\n");
                message("vision", victim->name() + "扭过头去，对" + me->name() + "理都不理。\n",
                        environment(me), ({ me, victim }) );
			me->delete_temp("checking");
                me->start_busy(3);
		}
}
string skill_level(string type, int level, string skill_name)
{
        string desc;
	int grade;

       if( stringp(desc = SKILL_D(skill_name)->query_lev_desc(level)) ) return desc;

	grade = level / 5;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int Random_Level(int lvl)
{
	if(lvl>120)
		return 0;
	else return random((int)(120-lvl)/10);

}
