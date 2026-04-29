//boss.c
//by dwolf
           
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(RED"老板"NOR, ({ "boss", "lao ban" }) );
        set("gender", "男性" );
        set("age", 36);       
	set("per", 18);
        set("long",
                "这是一位胖乎乎的矮个子，笑得眼睛都快没有了。\n");
        set("attitude", "friendly"); 

        setup();

	add("silver",10);
	carry_object("/d/hangzhou/npc/obj/cloth.c")->wear();
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
