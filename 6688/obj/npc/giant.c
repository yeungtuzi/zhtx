// /obj/npc/giant.c

inherit NPC;

void create()
{
        set_name("大驴", ({ "giant", "donkey", "ass" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "五百万年,五百万头里才会有一头出现的特级大驴!\n");
        set("str",61);
        set("cor",11);
        set("cps",13);
        set("con",61);
        set("int", 1);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "ram", "kick", "hoof" }) );
        set("max_kee",2000);
        set("attitude","peaceful");
        set("combat_exp",44444444);
        set("bellicosity",3);
        set_temp("apply/attack",50);
        set_temp("apply/armor",20);
        set_skill("dodge", 200);
        setup();
}
