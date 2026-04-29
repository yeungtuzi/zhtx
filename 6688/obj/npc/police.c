// /obj/npc/police.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("便衣警察", ({ "policeman", "police" }) );
        set("long", @LONG
这是个正在执行公务的便衣警察,虽然他们看上去和普通人没什么两样,但是
因为代表着国家的权威,所以自然而然地有一种威严.一般人谁也不轻易招惹
他们.
LONG
);

        set("attitude", "heroism");
        set("pursuer", 1);

        set("str", 30);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set_skill("unarmed", 70);
        set_skill("shooting", 70);

        setup();

        carry_object("/obj/cloth")->wear();
//        carry_object("/obj/longsword")->wield();
}


