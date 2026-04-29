// /obj/npc/horse.c

inherit NPC;

void create()
{
	set_name("马", ({ "horse", "ma" }) );
	set("race", "野兽");
	set("age", 1+random(4));
	set("long", "这是一匹普通的马,鞍鞯俱全,随时可供骑用.\n");
	set("str",15);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite", "ram", "kick", "hoof" }) );
	set("max_kee",200);
	set("attitude","peaceful");
	set("combat_exp", 4);
	set_skill("dodge", 20);
	setup();
}
