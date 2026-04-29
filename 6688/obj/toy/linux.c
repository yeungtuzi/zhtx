// /obj/toy/linux.c

inherit ITEM;

void create()
{
        set_name("linux光盘", ({ "linux cd", "linux", "cd" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张linux光盘.\n");
        set("value", 5000);
        set("skill", ([
                "name": "computer",
        "exp_required": 0,
            "sen_cost": 50,
          "difficulty": 55,
           "max_skill": 110,
        ]) );
        }
}
