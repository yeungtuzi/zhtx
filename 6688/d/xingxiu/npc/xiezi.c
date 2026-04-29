//xiezi.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("毒蝎", ({ "xie" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只好大好大的蝎子，尾巴高高翘起，充满杀机。\n");
        set("str", 34);
        set("combat_exp",4500);
        set("score", 40);
	set("poison_available", 50);
	set("can_get", 1);
        set("env/can_get", 1);
        set("force", 200);
        set("max_force", 200);
        set("max_kee",90);
        
        set("limbs", ({ "头部", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_temp("apply/attack", 30);
        set_temp("apply/armor", 20);
        set("chat_chance", 5); 
        set("chat_msg", ({
         "蝎子把尾巴翘得高高的.......\n",
}) );

        setup();
}

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("xiezi_poison") < 4 ) {
                ob->apply_condition("xiezi_poison", 8);
                tell_object(ob, YEL"你觉得被咬的地方一阵麻痒！\n"NOR );
        }
}
varargs void revive(int quiet)
{
	remove_call_out("revive");
	return;
}
