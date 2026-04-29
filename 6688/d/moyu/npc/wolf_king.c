//wolf_king.c
//by meteoric
#include <ansi.h>
inherit NPC;
inherit "/ldg/std/rnd_equipd.c";

void create()
{
        set_name(WHT"雪狼王"NOR, ({"wolf king","wolf","king" }) );
        set("race", "野兽");
        set("age", 5);
        set("long",WHT"雪狼之王。\n"NOR);
        
        set("str",155);
        set("cor",100);
        set("cps",45);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("max_kee",5000);
        set("attitude","aggressive");
        set("combat_exp",10000000);
        set("bellicosity",6000);
       
        set_temp("apply/attack",400);
        set_temp("apply/dodge", 100);
        set_temp("apply/armor",200);
        set_temp("apply/damage",100);
        set_skill("dodge", 500);
        
        if(random(10)>6) carry_rnd_equip(2,3);
        carry_object(__DIR__"obj/xldan");
        carry_object("/d/moyu/obj/nineflower");

        setup();
}
