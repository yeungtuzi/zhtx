// /obj/book/gchem.c

inherit ITEM;

void create()
{
        set_name("普通化学", ({"general chemistry","chemistry book","book"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本化学系学生用的基础教科书.\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "chemistry",
                  "base_skill": "physics",
            "base_skill_level": 20,
                "exp_required": 0,
                    "sen_cost": 40,
                "difficulty": 30,
                "max_skill": 45,
                ]) );
        }
}
