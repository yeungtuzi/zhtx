// /obj/book/houhei.c

inherit ITEM;

void create()
{
        set_name("厚黑学", ({ "hou hei xue","book" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","人生教科书--厚黑学,著者:李宗吾");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "politics",
                "exp_required": 0,
                    "sen_cost": 40,
                  "difficulty": 30,
                   "max_skill": 75,
                ]) );
        }
}
