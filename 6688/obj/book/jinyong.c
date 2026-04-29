// /obj/book/jinyong.c

inherit ITEM;

void create()
{
        set_name("金庸全集", ({ "jinyong quanji", "jin book", "book" }));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long","飞雪连天射白鹿,笑书神侠倚碧鸳\n");
                set("value", 49900);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",
                "exp_required": 0,
                    "sen_cost": 35,
                  "difficulty": 26,
                   "max_skill": 100,
                ]) );
        }
}
