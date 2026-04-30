// newbie area's guard
// 海娃
// by dongsw

#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
        // 2026-04-30: unused variable commented out
        // object ob;
        set_name("海娃", ({ "hai wa","boy"}) );
        set("gender", "男性" );
        set("age", 12);
        set("title", HIG"新手村 "CYN"接引使"NOR);
        set("long","他是新手村中年龄最小的人，但是他在新手村里面的地位可是非同一般，他是新手村\n"
                   "的接引使和导游。专门给新人介绍新手村的信息。\n");
        set("combat_exp", 100000);

        carry_object("/obj/cloth")->wear();
        setup();

}

