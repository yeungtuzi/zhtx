// /d/xizang/class/snow_mnt/npc/seng.c 进香客

inherit NPC;

void create()
{
	int value;

	value = random(10);

	set_name("僧人", ({ "seng ren", "guest", "seng" }));
	set("long", "这是一位来参加法会的僧人.\n");
	set("gender", "男性");
	set("age", 24 + value * 3 );
	set("combat_exp", 1500 + 50 * value);
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
	add_money("silver", 1 + value);
}
