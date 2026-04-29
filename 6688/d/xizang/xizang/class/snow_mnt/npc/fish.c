// /d/xizang/class/snow_mnt/npc/fish.c

inherit NPC;

void create()
{
	set_name("鱼", ({"fish"}));
	set("race", "野兽");
	set("age", 1+random(5));
	set("long", "一条大鱼.\n");
	set("str", 5);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("max_kee",300);
	set("combat_exp",4);
	set_skill("dodge", 200);
	setup();
}
