//snake5.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED"万毒蛇王"NOR, ({"king snake","snake"}) );
        set("long",     "一支昂首吐信的毒蛇正虎视眈眈地盯著你。\n");
        set("race", "野兽");
        set("age", 3);
        set("pursuer", 1);
        set("max_gin", 800);
        set("max_kee", 2000);
        set("max_sen", 800);
        set("str", 100);
        set("cor", 100);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 200);
        set("combat_exp", 10000000);
		set("shen_type",-1);
        setup();
		remove_call_out("dest_snake");
		call_out("dest_snake",60);
}

void dest_snake()
{
	tell_room(environment(this_object()),"\n"+query("name")+"突然之间"+
		"融化了，连一丝痕迹也没有留下……\n\n");
	destruct(this_object());
}

int hit_ob(object me, object ob, int damage)
{
	int n;
	n=(int)ob->query_condition("shw_poison");
	ob->apply_condition("shw_poison", 50+n);
	tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}

void die()
{
	object me,killer;
	write("\n"+query("name")+"发出一声凄惨的低鸣，死了。\n");
    me=this_object();
    if( objectp(killer = query_temp("last_damage_from")) )
	{
        set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, me);
	}
	destruct(this_object());
}
