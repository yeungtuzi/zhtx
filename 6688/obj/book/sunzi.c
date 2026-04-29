// /obj/book/sunzi.c

inherit ITEM;

void create()
{
        set_name("孙子兵法", ({ "sunzi bingfa", "bingfa", "book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("long","中国古代大军事家孙子的著作,乃一切兵家规律的总结.\n");
                set("value", 400);
                set("material", "paper");
                set("skill", ([
                        "name": "tactics",
                "exp_required": 100000,
                    "sen_cost": 40,
                  "difficulty": 40,
                   "max_skill": 999,
                ]) );
        }
}
