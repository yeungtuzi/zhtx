// /obj/toy/xo.c

inherit ITEM;

void create()
{
        set_name("笑熬浆糊源码", ({ "xo disk", "xo", "disk" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张1.44寸软盘.\n");
        set("value", 50);
        set("skill", ([
                "name": "computer",
        "exp_required": 0,
            "sen_cost": 30,
          "difficulty": 35,
           "max_skill": 90,
        ]) );
        }
}
