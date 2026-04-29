//by tlang
           
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("商人", ({ "shang ren", "ren" }) );
        set("gender", "男性" );
        set("age", 36);       
        set("long","一位出来采购货物的商人。\n");

        set("attitude", "friendly"); 
	set("combat_exp",20000);

	set_skill("blade",50);
	set_skill("dodge",50);
	set_skill("parry",50);

        setup();

	add_money("silver",10);
	carry_object("/d/hangzhou/npc/obj/girth2.c")->wear();
	carry_object("/d/suzhou/npc/obj/gangdao")->wield();
}


void init()
{
	add_action("do_rent","rent");
}

int do_rent(string arg)
{
	object me;

	me=this_player();

     	switch (MONEY_D->player_pay(me, 1000) )
	{
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		message_vision("$N从老板那里租下一条舟，然后跳了上去。\n",me);
		me->move("/d/hangzhou/xihu1");
		  return 1;
	}   
}
