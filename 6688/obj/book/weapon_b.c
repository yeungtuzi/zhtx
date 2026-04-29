// /obj/book/weapon_b.c

inherit ITEM;

void create()
{
        set_name("十八般兵器", ({ "weapon book", "parry book", "book" }));
        set_weight(1300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本讲解各种冷兵器使用的书.\n");
                set("value", 4500);
                set("material", "paper");
                set("skill", ([
                        "name": "parry",
                "exp_required": 10000,
                    "sen_cost": 35,
                  "difficulty": 28,
                   "max_skill": 75,
                ]) );
        }
}
