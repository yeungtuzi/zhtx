// /obj/book/mao.c

inherit ITEM;

void create()
{
        set_name("毛选", ({ "mao xuan", "mao book", "book" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本毛泽东选集.\n");
                set("value", 800);
                set("material", "paper");
                set("skill", ([
                        "name": "politics",
                "exp_required": 0,
                    "sen_cost": 60,
                  "difficulty": 45,
                   "max_skill": 99,
                ]) );
        }
}
