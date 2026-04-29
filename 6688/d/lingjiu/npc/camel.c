// deer.c

inherit NPC;

void create()
{
        set_name("骆驼", ({ "camel" }) );
        set("race", "野兽");
        set("age", 9);
        set("long", "一头骆驼，用做在沙漠干旱之地行走和运输的工具！\n");
        set("str", 40);
        set("cor", 15);
        set("score",-40);
        set("attitude","friendly");
        set("gin", 400);
        set("max_gin", 400);
        set("sen", 400);
        set("max_sen", 400);
        set("kee", 1500);
        set("max_kee", 1500);
        set("combat_exp", 7000);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );
	set_temp("apply/armor", 30);
        set_temp("apply/defense", 30);
        setup();
}
