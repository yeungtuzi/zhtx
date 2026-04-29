// /obj/book/gulong.c

inherit ITEM;

void create()
{
        set_name("古龙全集", ({ "gulong quanji", "gu book", "book" }));
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long","武侠小说家古龙的全部作品,结集在此.\n");
                set("value", 59900);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",
                "exp_required": 0,
                    "sen_cost": 35,
                  "difficulty": 24,
                   "max_skill": 98,
                ]) );
        }
}
