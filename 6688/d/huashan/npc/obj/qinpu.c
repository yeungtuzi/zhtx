//广陵散
//qinpu.c
inherit ITEM;

void create()
{
        set_name("广陵散", ({ "guangling san","qinpu", "pu" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 1);
                set("material","paper");
                set("long", "这就是传说中的广陵散。\n");
                set("skill", ([
                        "name" : "music",     // name of the skill
                        "exp_required": 5000,  // minimum combat experience required
                        "sen_cost": 50+random(30),// jing cost every time study this skill
                        "difficulty":   50,     // the base int to learn this skill
                        "base_skill":   50,
                        "max_skill":   150 
                      ]) );

                }
        setup();
}

