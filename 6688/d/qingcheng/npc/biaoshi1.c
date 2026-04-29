// worker.c
#include <ansi.h>
inherit NPC;

int do_protect(object boss);
void create()
{
        set_name(RED"红衣镖师"NOR, ({ "redcloth guard","guard" }) );
        set("gender", "男性" );
        set("long", "一个身穿红衣的镖师正在等着人来雇佣(employment)。\n");
        set("attitude", "friendly");
        set("inquiry", ([
                "employment": "在下一天的保护费只要五两黄金，阁下只管吩咐。",
                        ]) );
        set("age", 27);
        set("str", 30);
	set("cor",30);
	set("shen_type", 1);
	set("combat_exp",150000);
	set_skill("unarmed",80);
	set_skill("dodge",80);
	set_skill("parry",80);
	set_skill("notracesnow",50);
	set_skill("celestrike",60);
	set_skill("spring-blade",50);

	map_skill("unarmed","celestrike");
	map_skill("dodge","notracesnow");
	map_skill("parry","spring-blade");
	
	set_temp("apply/force_factor", 30);
        setup();

        carry_object(__DIR__"obj/redcloth")->wear();
}

void init()
{
	add_action("accept_order", "order");
	add_action("do_protect","protectme");
}

int accept_order(string arg)
{       object me=this_player();
        if( (int)me->query("id") ==query("boss_id") )
	 {
                switch(arg) {
                        case "kill":
                                command( "say 我只是负责保护你的，杀人的事我可不想干.");
                                return 0;
                        case "fight":
                                command( "say 学武只是为了防身，这位"+ RANK_D->query_respect(me)
                                        + "您可也不要持武欺人啊!\n");
                                return 0;
                        default:
                                command(arg);
                                return 1;
                }
        }
        return 0;
}
/*
int accept_order(string str)
{
        object me;
        string tmp1, tmp2,name;
        me = this_player();
	name=this_object()->query("name");
        if (!str) return 0;
	 if( (int)me->query("id") ==query("boss_id") )
        if (sscanf(str,"guard to %s %s",tmp1, tmp2) == 2) {
                if ( tmp1 =="kill")  
		{ command( "say 我只是负责保护你的，杀人的事我可不想干.");
		  return 1;}
                  else
		command( "temp1 temp2");
		 return 1;
        }
        else return 0;
        return 0;
}*/
int accept_info(object me, string command)
{
        return (string)me->query("id") == (string)query("boss_id");
}

int accept_object(object me, object obj)
	{
        if( query("boss_id") ) {
                command( " say 对不起，在下已经有人雇了。");
                return 0;
        	}

        if( (int)obj->value() < 50000 ) {
                command( " say 五两黄金一天，一个子儿也不能少。");
                return 0;
	        }
        set("boss_id", me->query("id"));
        call_out("end_duty", (obj->value()/50000) * 1440 );
        command("say 谢谢这位" + RANK_D->query_respect(me) +"!遇到危险时只管叫我保护你(protectme)!\n");
        command("follow " + me->query("id"));
        return 1;
	}

int do_protect(object boss)
{
	boss = this_player();
	if( (int)boss->query("id") ==query("boss_id") )
	{
		if( !boss->is_fighting() )
	                return notify_fail("没有人要杀你！\n");	
		else if( boss->is_busy() )
		{
			return notify_fail("你正忙着呢! \n");
		}
		else
		{
			this_object()->invocation(boss);
			boss->remove_all_killer();
			return 1;
		}
	}
	else return 0;
}

void end_duty()
{
        command("tell " + query("boss_id") + " 我只能保护你到现在了，下次再会。");
        command("bow");
        delete("boss_id");
}
