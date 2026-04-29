//s_jm.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"居民"NOR, ({ "ju min" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "一个普通的居民。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 20);
        set_skill("parry", 20);

        setup();
        add_money("silver", 1);
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/example/dagger")->wield();
}

