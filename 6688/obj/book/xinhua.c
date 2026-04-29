// /obj/book/xinhua.c

inherit ITEM;

void create()
{
        set_name("新华字典", ({ "xinhua dictionary", "dictionary" }));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","新华字典,商务印书馆出版.\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "literate",
                "exp_required": 0,
                    "sen_cost": 30,
                  "difficulty": 12,
                   "max_skill": 60,
                ]) );
        }
}
