// /obj/book/matheco.c

inherit ITEM;

void create()
{
        set_name("经济数学", ({ "eco-math book", "book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("long","这是本经济数学教科书,主要供经济学方面的学生使用.\n");
                set("value", 3100);
                set("material", "paper");
                set("skill", ([
                        "name": "maths",
                  "base_skill": "economics",
            "base_skill_level": 30,
                "exp_required": 0, 
                "sen_cost":  45,
                "difficulty":30,
                "max_skill": 80,
                ]) );
        }
}                             
