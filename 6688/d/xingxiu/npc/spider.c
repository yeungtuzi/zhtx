//xiezi.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("毒蜘蛛", ({ "spider" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只好大好大的蜘蛛，全身五彩斑斓。\n");
        set("str", 34);
        set("combat_exp",4500);
        set("score", 40);
	set("can_get", 1);
        set("env/can_get", 1);
	set("poison_available", 50);
        set("force", 200);
        set("max_force", 200);
        set("max_kee",90);
        
        set("limbs", ({ "身体" }) );
        set("verbs", ({ "bite" }) );

        set_temp("apply/attack", 30);
        set_temp("apply/armor", 20);

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
