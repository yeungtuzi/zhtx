// /obj/book/qchem.c

inherit ITEM;

void create()
{
        set_name("量子化学", ({"quantum chemistry","chemistry book","book"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本化学系学生用的量子化学教科书.\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "chemistry",
                  "base_skill": "chemistry",
            "base_skill_level": 30,
                "exp_required": 0,
                    "sen_cost": 60,
                "difficulty": 35,
                "max_skill": 85,
                ]) );
        }
}
