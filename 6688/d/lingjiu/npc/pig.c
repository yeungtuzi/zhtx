// deer.c

inherit NPC;

void create()
{
        set_name("野猪", ({ "pig" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只又肥又大的野猪，在雪地里乱窜！\n");
        set("str", 50);
        set("cor", 56);
	set("cps", 5);
        set("attitude","aggressive");
        set("gin", 400);
        set("max_gin", 400);
        set("sen", 400);
        set("max_sen", 400);
        set("kee", 1000);
        set("max_kee", 1000);
        set("combat_exp", 70000);
	set("shen_type", -1);
	
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set_temp("apply/defense", 30);
        setup();
}
