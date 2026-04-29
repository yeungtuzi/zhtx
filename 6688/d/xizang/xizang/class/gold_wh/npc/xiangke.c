// /d/xizang/class/gold_wh/npc/xiangke.c

inherit NPC;

void create()
{
	int value;
	value = random(10);
	set_name("香客", ({ "xiang ke", "ke", "guest" }));
	if (random(30)>22) set("gender", "女性");
		else set("gender", "男性");
	set("long", "一位到札什伦布寺来参拜的香客.\n");
	set("age", 14 + value * 3 );
	set("combat_exp", 500 + 5 * value);
	set("shen_type", 0);
	set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	add_money("silver", 1 + value);
}
