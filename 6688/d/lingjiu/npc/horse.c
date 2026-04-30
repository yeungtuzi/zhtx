//horse.c
inherit NPC;

void create()
{
        // 2026-04-30: unused variable commented out
        // int i;
        
        set_name("骏马", ({ "horse" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一匹浑身雪白的骏马。\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        
        set("max_kee",150);
        set("str",45);
        set("combat_exp", 15000);

        setup();
}
