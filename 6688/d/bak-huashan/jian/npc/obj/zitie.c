//张旭率意帖
//zitie.c
inherit ITEM;

void create()
{
        set_name("张旭率意帖", ({ "shuaiyi tie","zitie", "tie" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("value", 1);
                set("long", 
"帖上的草书大开大阖，便如一位武林高手展开轻功，窜高伏低，\n"
"虽然行动迅捷，却不失高雅的风致，但见帖尾写满了题跋，盖了\n"
"不少图章，料想此帖的是非同小可。\n");
                set("skill", ([
                        "name" : "caoshu",     // name of the skill
                        "exp_required": 5000,  // minimum combat experience required
                        "sen_cost": 50+random(30),// jing cost every time study this skill
                        "difficulty":   50,     // the base int to learn this skill
                        "max_skill":   150,
                        "base_skill":  100, 
                      ]) );

                }
        setup();
}

