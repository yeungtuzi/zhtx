// /obj/book/gphysics.c

inherit ITEM;

void create()
{
        set_name("普通物理", ({ "general physics", "physics book", "book" }));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本物理系学生用的基础教科书.\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "physics",
                "exp_required": 0,
                    "sen_cost": 40,
                "difficulty": 30,
                "max_skill": 45,
                ]) );
        }
}
