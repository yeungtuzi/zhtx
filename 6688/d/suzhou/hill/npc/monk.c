//monk.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"知客僧"NOR, ({ "monk" }) );
        set("gender", "男性" );
        set("age", 28);
        set("long", "专门负责接待香客的和尚。\n");
       
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("shen_type",2);

	set_skill("dodge",20);
	set_skill("parry",30);
	set_skill("unarmed",10);

        setup();
        add_money("silver", 1);
        carry_object("/d/suzhou/npc/obj/qing-cloth")->wear();
}

