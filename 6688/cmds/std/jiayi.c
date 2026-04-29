//
// 武道禅宗，嫁衣神功，内力修炼一生，不过为人作嫁，一场春梦
// by yeung

#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{       
	int skill,force,max_contain_force,i;  
	mapping skills;
	object target;            
	string *skname;
	
	seteuid(getuid());
	
	if( wizardp(me) )
		return notify_fail("巫师不可以使用嫁衣神功。\n");

	if( me->query_skill_mapped("force") != "jiayiforce" )
		return notify_fail("你的内功没有这项功能。\n");

        if( !arg )
                return notify_fail("你想给谁嫁衣？\n");

        if(!objectp(target = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

	skill = me->query_skill("jiayiforce",1);  
	if(skill < 105) return notify_fail("你的嫁衣神功太差了，不能为人作嫁！\n"); 
	
	if( !target || target == me)  return notify_fail("你要对谁使用嫁衣神功？\n" );

        if( target->is_busy() )
                return notify_fail("对方正忙著做其他事！\n");
		
        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法使用嫁衣神功！\n");
                
	if((int)me->query("max_force") < 1000)
                return notify_fail("你的内力不够强。\n");                

	max_contain_force = (target->query_skill("force",1)*5+target->query_skill("force"))*2 + 500;

	if( (int)me->query("max_force") < max_contain_force )	
	{
		return notify_fail("你的内力还不够强,强行为人嫁衣，会让对方元气大伤。\n");                		
	}	
	                                                                                                  	                                                                                                  
	log_file("JIAYI",sprintf("%s(%s) transfers force to %s(%s) on %s\n",
                me->name(1), geteuid(me), target->name(1), geteuid(target),ctime(time()) ) );

	message_vision(HIY"$N和$n盘膝坐下，$N运起嫁衣神功，将真气缓缓输入$n体内...\n\n"NOR,me,target);	

// delete my skills

	me->skill_death_penalty(1);

        skills = me->query_skills();
        if( mapp(skills) ) {
                skname = keys(skills);
                for(i=0; i<sizeof(skname); i++)
                        skills[skname[i]] = 0;
        }

        skills = me->query_learned();
        if( mapp(skills) ) {
                skname = keys(skills);
                for(i=0; i<sizeof(skname); i++)
                        skills[skname[i]] = 0;
        }
				
// 	start jiayi

	me->set_temp("accepter",target);
	target->set_temp("performer",me);

        me->start_busy(
                bind((: call_other, __FILE__, "do_jiayi", me, me->query("max_force") :), me),
                bind((: call_other, __FILE__, "interrupt_jiayi" :), me) );
        me->add_temp("apply/short", ({ me->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." }) );		

        target->start_busy(
                bind((: call_other, __FILE__, "do_accept", target, target->query("max_force") :), target),
                bind((: call_other, __FILE__, "interrupt_jiayi" :), target) );
        target->add_temp("apply/short", ({ target->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." }) );		
	
        return 1;
}

int do_jiayi(object me, int low_kee)
{
        int cycle,max_contain_force;
        object partner;  
        cycle = 100;
        
	if( !objectp(partner=me->query_temp("accepter")) )
	{
                string *short;
		tell_object(me,"突然发现送出去的真气再无着落，啊...\n");	              	
                short = me->query_temp("apply/short");
                short -= ({ me->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." });
                me->set_temp("apply/short", short);
                me->delete_temp("accepter");
                me->unconcious();                 		                
                return 0;		
	}
        if( (int)me->query("max_force") < cycle ) {
                string *short;
		me->set("max_force",0);
		me->set("force",0);
                message_vision("$N行功完毕，虚弱的站了起来，突然一阵头晕目眩...\n", me);
                short = me->query_temp("apply/short");
                short -= ({ me->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." });
                me->set_temp("apply/short", short);
                me->delete_temp("accepter");      
                me->set("mark/jiayi",300);
                me->unconcious();   		                
                
		message_vision("$N缓缓将体内真气收束丹田，站了起来...\n", partner);
		max_contain_force = (partner->query_skill("force",1)*5+partner->query_skill("force"))*2 + 200;
		if( partner->query("max_force") > max_contain_force )
		{
			tell_object(partner,"你虽然努力将真气化入丹田，但还是有部分真气无法容纳，消散在你的经脉中。\n");
			partner->set("max_force",max_contain_force);
		}
                short = partner->query_temp("apply/short");
                short -= ({ partner->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." });
                partner->set_temp("apply/short", short);
                partner->delete_temp("performer");                

                return 0;
        }
              
	tell_object(me,HIY"你缓缓催动真气，一道道真气顺你的掌心送了出去...\n"NOR);	
        me->add("max_force", -cycle);

	tell_object(partner,HIY"你只觉得后心处一道道真气缓缓传来，经你运功化解，真气渐渐化入丹田，与原有真气融为一体...\n"NOR);	
        partner->add("max_force", cycle/2);
        
        return 1;
        
}

int do_accept(object me, int low_kee)
{
	return objectp(me->query_temp("performer"));	
}

int interrupt_jiayi(object me, object who, string reason)
{
        string *short;      
        object partner;

        switch(reason) {
        case "halt":
		write(HIR"嫁衣神功一旦施用，就不能再停止了！\n"NOR);
		return 0;		
        case "hit":
                tell_object(me, HIR "\n你觉得丹田一阵绞痛，受击之下，真气突然茬了气脉！\n\n" NOR);
                message_vision(HIR "$N「哇」地一声喷出一大口鲜血，摇摇晃晃地站了起来。\n" NOR, me);
                me->set("max_force", (int)me->query("max_force") / 2 );
                me->set("force",0);
		if( objectp( partner = me->query_temp("performer") ) && partner->query_temp("accepter")==me )
		{
			partner->delete_temp("accepter");
			me->delete_temp("performer");									
			partner->interrupt_me(who,"hit");
		}
		if( objectp( partner = me->query_temp("accepter") ) && partner->query_temp("performer")==me )
		{
			partner->delete_temp("performer");
			me->delete_temp("accepter");
			partner->interrupt_me(who,"hit");
		}	
                break;
        }
        short = me->query_temp("apply/short");
        short -= ({ me->name() + "满头大汗淋漓，正在艰难的运转体内真气 ...." });
        me->set_temp("apply/short", short);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : jiayi <某人>

这是武林中一项神秘功夫 － 嫁衣神功的独特功能，取义于
“武道禅宗，嫁衣神功，内力修炼一生，到头来不过为人作嫁，一场春梦”。

嫁衣神功威猛雄强，却难以修炼，每到一次进步的时候，就难以控制，
修炼起来，实在是难上加难。 自古以来，只有大侠燕南天得以武功大成，
其中应有非凡的际遇。

HELP
        );
        return 1;
}
