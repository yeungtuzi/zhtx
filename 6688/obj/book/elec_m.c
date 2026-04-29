// /obj/book/elec_m.c

inherit ITEM;

void create()
{
        set_name("电动力学", ({ "electrodynamics", "book"}) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本物理系学生用的电动力学教科书.\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "physics",
                "exp_required": 0,
                    "sen_cost": 60,
                "difficulty": 35,
                "max_skill": 85,
                ]) );
        }
}
