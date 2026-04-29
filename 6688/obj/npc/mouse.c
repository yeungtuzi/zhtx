// /obj/npc/mouse.c

inherit NPC;

void create()
{
        set_name("老鼠", ({"mouse"}) );
        set("race", "野兽");
        set("age", 1);
        set("long", "一只灰不溜秋的小老鼠.\n");
        set("str",11);
        set("cor",11);
        set("cps",15);

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("max_kee",100);
        set("attitude","peaceful");
        set("combat_exp",400);
        set("bellicosity",3);
        set_temp("apply/attack",10);
        set_temp("apply/armor",2);
        set_skill("dodge", 240);
        setup();
}


