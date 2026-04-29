// deer.c

inherit NPC;

void create()
{
        set_name("梅花鹿", ({ "deer" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只很肥的梅花鹿，在雪地里蹦蹦跳跳，全然没有注意自己处境危险！\n");
        set("str", 10);
        set("cor", 46);
        set("score",-40);
        set("attitude","friendly");
        set("gin", 400);
        set("max_gin", 400);
        set("sen", 400);
        set("max_sen", 400);
        set("kee", 1000);
        set("max_kee", 1000);
        set("combat_exp", 7000);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/defense", 30);
        setup();
}
