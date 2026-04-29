// /d/xizang/npc/wolfx.c

inherit NPC;

void create()
{
        set_name("雪山狼", ({ "snow wolf", "wolf" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只凶残的雪山狼,嘴边上还留着血迹.\n");
        
        set("str",15);
        set("cor",52);
        set("cps",15);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
	set("max_kee",10000);
	set("kee", 10000);
        set("attitude","aggressive");
        set("combat_exp",500000);
        set("bellicosity",30000);
       
        set_temp("apply/attack",100);
        set_temp("apply/armor",90);
        set_skill("dodge", 300);

        setup();
}
