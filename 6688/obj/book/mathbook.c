// /obj/book/mathbook.c

inherit ITEM;

void create()
{
        set_name("高等数学教程", ({ "math book", "book"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是大学理科学生必修的高等数学教科书.\n");
                set("value", 2000);
                set("material", "paper");
                set("skill", ([
                        "name": "maths",
                "exp_required": 0,
                  "base_skill": "maths",
            "base_skill_level": 30,
                    "sen_cost": 35,
                  "difficulty": 40,
                   "max_skill": 75,
                ]) );
        }
}
