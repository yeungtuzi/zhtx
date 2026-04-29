// /obj/book/toefl.c

inherit ITEM;

void create()
{
        set_name("TOEFL词汇", ({ "toefl book", "toefl", "book"}));
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","TOEFL词汇,玉米糊编著.\n");
                set("value", 4000);
                set("material", "paper");
                set("skill", ([
                        "name": "english",
                "exp_required": 0,
                    "sen_cost": 30,
                  "difficulty": 25,
                   "max_skill": 80,
                ]) );
        }
}
