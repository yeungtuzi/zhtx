//snow wolf.c
//by meteoric
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(WHT"雪狼"NOR, ({"snow wolf","wolf" }) );
        set("race", "野兽");
        set("age", 5);
        set("long",WHT"一只生长于雪地的雪狼，很少成群结队出没于雪原之上，\n"
        	      "但是一旦碰上成群的雪狼，后果不堪设想。\n"NOR);
        
        set("str",55);
        set("cor",100);
        set("cps",45);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("max_kee",3000);
        set("attitude","aggressive");
        set("combat_exp",2000000);
        set("bellicosity",3000);
       
        set_temp("apply/attack",200);
        set_temp("apply/armor",140);
        set_skill("dodge", 320);
        set("not_dyna_npc",1);
        

        setup();
}
