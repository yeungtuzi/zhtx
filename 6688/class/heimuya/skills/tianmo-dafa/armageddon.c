// _busymageddon.c
// 玉石俱焚
// by YEUNG

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int do_prepare(object me,object target);
int interrupt_prepare(object me,object who,string reason);

void create() { seteuid(getuid()); set("name","江湖传说");set("id","ARMAGEDDON");}

int exert(object me, object target)
{
        int skill,i;
        object *obs;

	seteuid(ROOT_UID);

        if( !me->is_fighting() )
        	return notify_fail("「玉石俱焚」只能在战斗中施用。\n");        	                     
	
        if( userp(me) && (int)me->query("force") < 2000 ) return notify_fail("你的内力不够。\n");
        
        if( !target || target == me ) target = offensive_target(me);

        skill = me->query_skill("force")+me->query_skill("tianmo-dafa",1);


        message_vision(HIR"$N脸上现出凄厉之色，身形突然快速旋转起来，面上血色全部褪去.\n" NOR, me);
        me->add_temp("apply/defense",100);
        me->add_temp("apply/attack",-100);
        obs = filter_array( all_inventory(environment(me)) , (:$1->is_character()&&!$1->is_corpse():) );
        obs -= ({me});
        i = sizeof(obs);
        while( i-- )
        {
        		me->kill_ob(obs[i]);	
        		if( !userp(obs[i]) )
        			obs[i]->kill_ob(me);
        		else
        			obs[i]->fight_ob(me);
        }	
	me->set_temp("prepare_armageddon",5);        
	environment(me)->set_temp("lock_scene","$N意欲离开，可是强劲的力场将$N牢牢锁住。\n");	
          seteuid(ROOT_UID);
        me->start_busy(
                bind((: call_other, __FILE__, "do_prepare", me, target :), me),
                bind((: call_other, __FILE__, "interrupt_prepare" :), me) );
        //        0 );
        return 1;
}

int do_fire(object me,object target)
{
	int damage,i;
	object *obs;
        
        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);	

	damage = me->query_skill("force")+me->query_skill("tianmo-dafa",1);		
	damage *= (5 + random(5));
	
	me->set("force",0);
	me->delete_temp("prepare_armageddon");
	if( !target )
		message_vision(HIR"\n惊人的真劲，从$N身周爆开，以惊人的高速扩散波及达周围空间，\n"NOR,me);
	else
	{
		message_vision(HIR"\n惊人的真劲，从$N身周爆开，以惊人的高速扩散波及达周围空间，\n"NOR,target);

	
	        if( (damage-target->query_temp("apply/armor_vs_force")) > 0 )
        	{        
        		target->receive_wound("kee",damage-target->query_temp("apply/armor_vs_force"),me);
        		//对NPC杀伤更大一些
        		if( !userp(target) )
        			target->receive_wound("kee",damage,me);
        		COMBAT_D->report_status(me,target,1);        		
		}
		else
		{
			message_vision(GRN"可是$N还是在最后一刻拼尽全力抵挡住了这最后致命一击！\n");        	
			target->set("force",0);
		}
	}
        message_vision(RED"\n与此同时，$N爆作漫天精血碎粉，身体神迹般消失得无影无踪。\n",me);
        
        message_vision(HIR"致命的气劲把一切淹没....\n\n",me);
        obs = all_inventory(environment(me));
        obs -= ({me,target});                
        i = sizeof(obs);
        while( i-- )
        {
        	if( obs[i]->is_character() && obs[i]->query("max_kee") )
		{
		        if( (damage/2-obs[i]->query_temp("apply/armor_vs_force")) > 0 )
        		{        
        			write("...\n");
        			message_vision("只听见「砰」地一声巨响，$N狂吐鲜血，身子象断了线的风筝一般向外飞去！！\n",obs[i]);
        			obs[i]->receive_wound("kee",damage/2-obs[i]->query_temp("apply/armor_vs_force"),me);
        			if( !userp( obs[i] ) )
 					obs[i]->receive_wound("kee",damage/2,me);       			
        			//COMBAT_D->report_status(me,obs[i],1);
			}				
		}
        }	                                                     
        write(""NOR);         
	target->check_status();        
        obs->check_status();
	environment(me)->delete_temp("lock_scene");
	CHANNEL_D->do_channel(this_object(),"rumor","传说"+me->name()+"施用玉石俱焚,形神俱灭了。");
	//因为有可能是假死，并且会有尸体啊，谣言的很烦，换个调用
	me->die(1);
}	

int do_prepare(object me,object target)
{
	int left_busy;
	
	me->add_temp("prepare_armageddon",-1);
	left_busy = me->query_temp("prepare_armageddon");

        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);	

	if( left_busy > 3 )
	{
		message_vision(HIR"$N嘴角鲜血不绝渗出，天魔劲场不住收窄缩紧...\n"NOR,me);
		return 1;
	}	
	if( left_busy > 2 )
	{
		if(target)
			message_vision(HIR"$N的天魔劲场不住收窄缩紧，笼罩以$n为中心周围的方丈之地，$N的脸色变得愈发血红...\n"NOR,me,target);
		else
			message_vision(HIR"$N的天魔劲场不住收窄缩紧，笼罩着周围的方丈之地，$N的脸色变得愈发血红...\n"NOR,me,target);
		return 1;
	}	
	if( left_busy > 1 )		
	{
		message_vision(HIR"$N目射奇光，瞳孔紫芒刻盛，身形愈趋缓慢，带起的呼啸声却不断增强...\n"NOR,me,target);		
		return 1;
	}		
	if( left_busy > 0 )		 
	{
		if(target)
			message_vision(HIR"正在激战之中，$N忽然厉声长啸，天魔劲场倏地以$n为中心收缩，细窄至近一点.\n"NOR,me,target);
		else
			message_vision(HIR"$N忽然厉声长啸，天魔劲场倏地收缩，细窄至近一点.\n"NOR,me,target);
		return 1;
	}		
	do_fire(me,target);
	return 0; 
}	
                              
int interrupt_prepare(object me,object who,string reason)
{
        switch(reason) 
        {
        	case "halt":
        	        return notify_fail(HIR"「玉石俱焚」一旦施用，必定敌我偕亡，就无法再停止了！\n"NOR);
	                break;
        	case "hit":
                         if( random(who->query("force_factor")+who->query("force")) < (me->query_skill("tianmo-dafa",1)+me->query("force"))/2 ) return 0;
                	message_vision(HIR "$N一击命中，真气透入$n体内，及时截断了$n的气脉！\n" NOR, who,me);
                	tell_object(me,HIR"你只觉得全身真气突然在玉枕穴堵塞不前，随后不受控制地狂奔乱窜起来，啊～～!\n"NOR);
                	me->set("force",0);
                	me->unconcious();
                break;
	}
	environment(me)->delete_temp("lock_scene");        
        return 1;	
}	                               

