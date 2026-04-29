// /obj/book/wavelet.c

inherit ITEM;

void create()
{
        set_name("小波分析", ({ "wavelet analyse", "wavelet book", "book"}));
        set_weight(800);        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本物理系和数学系研究生用的数学参考书.\n");
                set("value", 2500);
                set("material", "paper");
                set("skill", ([
                        "name": "maths",
                "exp_required": 0,
                "sen_cost":  60,
                "difficulty":55,
               "base_skill": "maths",
         "base_skill_level": 80,
                "max_skill": 150,
                ]) );
        }
}
