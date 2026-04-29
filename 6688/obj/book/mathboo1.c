// /obj/book/mathboo1.c

inherit ITEM;

void create()
{
        set_name("中学数学", ({ "math book", "book" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是中学生用的数学教科书,比较简单.\n");
                set("value", 400);
                set("material", "paper");
                set("skill", ([
                        "name": "maths",
               "exp_required": 0,
                "sen_cost":  30,
                "difficulty":15,
                "max_skill": 30,
                ]) );
        }
}
