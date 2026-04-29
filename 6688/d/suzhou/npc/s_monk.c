//s_monk.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"扫地和尚"NOR, ({ "sao di monk","monk" }) );
        set("gender", "男性" );
        set("age", 18);
        set("long", "葫芦庙的扫地和尚，看上去好象有什么心事。\n");
       
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("shen_type",-2);

        setup();
        add_money("silver", 1);
        carry_object("/d/suzhou/npc/obj/qing-cloth")->wear();
}

