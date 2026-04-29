// /obj/book/math_hb.c

inherit ITEM;

void create()
{
        set_name("数学手册", ({ "math handbook", "handbook", "book" }));
        set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本收录各类数学公式的数学手册.\n");
                set("value", 3300);
                set("material", "paper");
                set("skill", ([
                        "name": "maths",
               "exp_required": 0,
                "sen_cost":  50,
                "difficulty":30,
                "max_skill": 80,
                ]) );
        }
}
