//s_jyc.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM"贾雨村"NOR, ({ "jia yucun","jia" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "一个落泊书生，虽然读着书，但显然有些心事。\n");
       
        set("combat_exp", 250000);
        set("attitude", "friendly");
        set("shen_type",-2);

	set_skill("literate",100);
	set_skill("parry",50);

        setup();
        add_money("silver", 1);
        carry_object("/d/suzhou/npc/obj/qbcloth")->wear();
}

