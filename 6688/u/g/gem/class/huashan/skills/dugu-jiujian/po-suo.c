//独孤九剑破索式
//by Emote 5/20/2000
#include <ansi.h>
#include <dugu.h>
inherit F_DBASE;
inherit SSERVER;

int do_prepare(object me,object target);
int interrupt_prepare(object me,object who,string reason);

void create() { seteuid(getuid()); set("name","江湖传说");set("id","rumord");}

int perform(object me, object target)
{
        int skill;
        object ob;
        seteuid(ROOT_UID);
        if( !me->is_fighting() )
        	return notify_fail("「破索式」只能在战斗中施用。\n");        	                     
	if( me->is_busy())
	        return notify_fail("你正忙着呢，来不及用独孤九剑。\n");
	if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用独孤九剑的「破索式」。\n");	
         
        if( !target || target == me ) target = offensive_target(me);

        skill = me->query_skill("dugu-jiujian",1);
	
        
        if( skill < 150 ) return notify_fail("你的「独孤九剑」招式不够娴熟，使不出「破索式」。\n");        	                     
        if( me->query_skill("whip",1)<150) return notify_fail("你的基本功不够扎实，无法使用「破索式」。\n");
          
        if( me->query("betrayer"))
            return notify_fail("你回想起以前在师门中所曾经受过的好处，再也无法使出独孤九剑来了。\n");
            
        if(!check_weapon(target,"whip")) 
            return notify_fail("对手手中并没有索，你如何使用「破索式」？\n");
        
        message_vision(HIY"$N使出独孤九剑「破索式」，静气凝神，仔细观察$n的一举一动，试图找出$n的破绽.\n" NOR, me,target);
        me->add_temp("apply/defense",100);
        me->set_temp("prepare_dugu",5);        
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
        object weapon,weap;
        
        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);	

	damage = me->query_skill("sword")+me->query_skill("dugu-jiujian",1);		
	damage /= 2;
	if(wizardp(me))
	CHANNEL_D->do_channel(this_object(),"sys",sprintf("damage==%d",damage));
	weapon = me->query_temp("weapon");
	weap   = target->query_temp("weapon");
	me->add("force",-500);
	me->add_temp("apply/defense",-100);
	
	me->delete_temp("prepare_dugu");
	{
		message_vision(HIR"\n只见$N挺剑刺出，正中$n的最薄弱之处。$n手中的"+weap->query("name")+"脱手飞出。\n"NOR,me,target);
                weap->unequip();
                weap->move(environment(me));
                if( (damage-target->query_temp("apply/armor_vs_force")) > 0 )
        	{        
        		//target->add("force",(target->query_temp("apply/armor_vs_force")-damage));
        		//对NPC杀伤更大一些
        		if( !userp(target) )
        			target->receive_wound("kee",damage,me);
        			
        		COMBAT_D->report_status(me,target,1);        		
        		//target->set("force_factor",0);
          	}
        	message_vision(RED"\n与此同时，$N手中的"+weapon->query("name")+"，再也无法承受巨大的真力的冲击，竟然被震碎成碎片。\n"NOR,me);
         	{
         	
                        weapon->unequip();
                        weapon->move(environment(me));
                        weapon->set("name", "破碎的" + weapon->query("name"));
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                        weapon->set("long", weapon->query("long")+"可是，现在却已经碎成几片，不知道还有什么用处。\n");
                        me->reset_action();
	  	}
	  }
        //CHANNEL_D->do_channel(this_object(),"rumor","传说"+target->query_name()+"被"+me->query_name()+"扎中了。");
	//因为有可能是假死，并且会有尸体啊，谣言的很烦，换个调用
		
}	

int do_prepare(object me,object target)
{
	int left_busy,ap,dp,lvl;
	
	me->add_temp("prepare_dugu",-1);
	left_busy = me->query_temp("prepare_dugu");

        me->clean_up_enemy();
        if( !target || target == me || target->is_corpse()) target = offensive_target(me);	

	if( left_busy > 3 )
	{
			if(check_user(me,target))
			{

		if(check_weapon(target,"whip"))
		{
				message_vision(HIY"$N不断左闪右躲，窥探着$n的要害之处...\n"NOR,me,target);
		 		return 1;
		}
		else
		{
	        tell_object(me,"对手手上已经没有鞭子了，没法使用「破索式」。\n");
 			me->delete("prepare_dugu");
 			me->add_temp("apply/defense",-100);
 			return 0;
 		}
		}
			else 
			{
				me->add_temp("apply/defense",-100);
				me->delete_temp("prepare_dugu");
				return 0;
			}

	}	
	if( left_busy > 2 )
	{
			if(check_user(me,target))
			{

		if(check_weapon(target,"whip"))
		{
				message_vision(HIY"$N不经意随手刺出几剑，以试探$n的虚实...\n"NOR,me,target);
				return 1;
		}
		else
		{
		    tell_object(me,"对手手上已经没有索了，没法使用「破索式」。\n");
 			me->delete("prepare_dugu");me->add_temp("apply/defense",-100);
 			return 0;
 		}
				}
			else 
			{
				me->add_temp("apply/defense",-100);
				me->delete_temp("prepare_dugu");
				return 0;
			}
		
	}	
	if( left_busy > 1 )		
	{
			if(check_user(me,target))
			{

		if(check_weapon(target,"whip"))
		{
			lvl = me->query_skill("sword");
			ap  = (lvl*lvl/7)*lvl;//学到头是不到600万power，大概是513万
			dp  = target->query("combat_exp");
			if( random(ap+dp)>dp)
				{
					message_vision(HIY"$N眼中灵光一闪，找出了$n的要害之处...\n"NOR,me,target);		
 					return 1;
 				}
	 		
 			else
 				{
 					message_vision(HIY"$N实在无法发现$n的要害之处，只得收起剑式。\n"NOR,me,target);
 					me->delete("prepare_dugu");me->add_temp("apply/defense",-100);
 					return 0;
		 		}
		}
		else
		{
		    tell_object(me,"对手手上已经没有索了，没法使用「破索式」。\n");
 			me->delete("prepare_dugu");me->add_temp("apply/defense",-100);
 			return 0;
 		}
			}
			else 
			{
				me->add_temp("apply/defense",-100);
				me->delete_temp("prepare_dugu");
				return 0;
			}
		
 		
	}		
	if( left_busy > 0 )		 
	{
			if(check_user(me,target))
			{

		if(check_weapon(target,"whip"))
		{
			object weapon;
			weapon=me->query_temp("weapon");
			message_vision(HIY"$N忽然长啸一声，手中"+weapon->query("name")+"向$n的要害快捷无伦地直刺而出。\n"NOR,me,target);
			return 1;
		}
		else
		{
		    tell_object(me,"对手手上已经没有索了，没法使用「破索式」。\n");
 			me->delete("prepare_dugu");me->add_temp("apply/defense",-100);
 			return 0;
 		}
			}
			else 
			{
				me->add_temp("apply/defense",-100);
				me->delete_temp("prepare_dugu");
				return 0;
			}
		
	}		
	do_fire(me,target);
	return 0; 
}	


int interrupt_prepare(object me, object who, string reason)
{
        
	me->add_temp("apply/defense",-100);
        switch(reason) {
        case "halt":
                tell_object(me,"「独孤九剑」一旦施用，就无法停止。\n");
                break;
        case "hit":
                message_vision(HIR "$N一击命中，真气透入$n体内，及时截断了$n的气脉！\n" NOR, who,me);
                tell_object(me,HIR"你只觉得全身真气突然堵塞不前，手中的剑式再也无法连贯地施用下去\n"NOR);
                me->start_busy(2+random(3));
                break;
        }
        return 1;
}
