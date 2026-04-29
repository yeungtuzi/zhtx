// /obj/book/fallen.c
// 转法轮

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("转法轮", ({ "fallen book", "book", "fallen" }));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","转法轮" HIC "李洪志" NOR "\n");
                set("material", "paper");
                set("value", 1000);
                set("skill", ([
                        "name": "fallen",
                "exp_required": 0,
                    "sen_cost": 33,
                  "difficulty": 15,
                   "max_skill": 999,
                  "base_skill": "literate",
            "base_skill_level": 20,
                ]) );
        }
}
