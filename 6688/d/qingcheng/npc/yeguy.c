#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"黄袍老道"NOR, ({ "yellow guy","guy" }) );
        set("gender", "男性" );
        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
	set("shen_type",-1);

        set("attitude", "peaceful");

        set("force_factor", 2);
        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);
        set("eff_gin", 1000);
        set("eff_kee", 1000);
        set("eff_sen", 1000);
        set("gin", 1000);
        set("kee", 5000);
        set("sen", 1000);
        set("max_atman", 300);
        set("atman", 300);
        set("max_force", 300);
        set("force", 300);
        set("max_mana", 300);
        set("mana", 300);

        set("long","白发飘飘仙风道骨的"+YEL"黄袍道人\n"NOR);


        set("combat_exp", 1000000);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);

        set_skill("qingcheng-force", 100);
        set_skill("cuixin-zhang", 110);
        set_skill("qingcheng-steps", 20);
        map_skill("force","qingcheng-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("dodge", "qingcheng-steps");

        setup();

        carry_object(__DIR__"obj/songzi")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}

void init()
{
        add_action("do_gogo", "go");
        add_action("do_north", "north");
}

int do_gogo(string arg)
{
        if( arg == "north" )
        {
            write("这个方向的路被"+YEL"黄袍道人"NOR+"挡住了 。\n");
            return 1;
        }
        return 0;
}
int do_north()
{           write("这个方向的路被黄袍道人挡住了 。\n");
            return 1;
}