//by dwolf
//boat.c

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE; 
inherit F_CLEAN_UP;

void create()
{
	set_name("龙舟", ({ "long zhou", "boat" }) );
        set("race", "野兽");
        set("age", 1000);
        set("long", "这是一头千年龙舟化的精，具有灵性。\n");
        set("attitude", "peaceful");
        set("str",30);
        set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("jing",1000); 
	set("max_neili",1000);
        set("max_qi", 3000);
	set("eff_qi", 3000);
	set("qi", 3000);

	set("combat_exp",10000);

	set_skill("dodge",200);
        set_skill("move",200);
	set_skill("unarmed",250);

	set("times",0);
	set("max_times",200);

	set("mout1","乘着龙舟往");
	set("mout2","奔去。\n");
	set("min","乘着龙舟威风凛凛地赶了过来。\n");
	
	setup();
}

void init()
{
	add_action("do_jump","jump");
	add_action("do_huan","huan");
}                 

int do_jump(string arg)
{
	object ob,me;

	ob=this_object();
	me=this_player();

	if( arg=="up" )
	{
		if( ob->query("hoster")==me->query("id") )
		{
			if( me->query_temp("jumped") )  return notify_fail(YEL"你已经跳到龙舟上了。\n"NOR);
			ob->set_leader(0);
	   		me->set_temp("jumped",1);
	   		message_vision(YEL"$N脚尖一点，上到龙舟上。\n"NOR,me); 
		
		}
		else
			message_vision(RED"$N身形一动，想上到龙舟上，结果掉进了西湖，狼狈不堪。\n"NOR,me); 

		return 1;
	}
	if(arg=="down")
	{
		if( ob->query("hoster")!=me->query("id") || !me->query_temp("jumped") )
			return notify_fail("你又没有在龙舟上，下什么下？\n");
		me->delete_temp("jumped");
		ob->set_leader(me);
		message_vision(YEL"$N身形一晃，跳下龙舟来。\n"NOR,me); 
		return 1;
	}

	return notify_fail(YEL"上舟( jump up ), 下舟( jump down ).\n"NOR);
}

int do_huan(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object(); 
        
        if( arg=="龙舟" || arg=="boat")  
        me->set("mark/舟", 1);
        message_vision("$N把舟栓到船铺边，对老板说：舟就还给你了。\n",me);
        destruct(ob);
                return 1;
}
