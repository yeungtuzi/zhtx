//s_xmei.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"心眉和尚"NOR, ({ "xin mei","monk" }) );
        set("gender", "男性" );
        set("age", 58);
        set("long", "葫芦庙的主持，看上去没有任何表情。\n");
       
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("parry", 100);
	set_skill("dodge",100);

        setup();
        add_money("silver", 1);
        carry_object("/d/suzhou/npc/obj/dao-cloth")->wear();
}

