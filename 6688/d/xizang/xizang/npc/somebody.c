// /d/xizang/npc/somebody.c

inherit NPC;

void create()
{
	set_name("陌生人", ({ "somebody" }) );
	if (random(10)>7) set("gender", "女性"); 
		else set("gender", "男性" );
	set("age", 25+random(16));
	set("long", "一个普通的藏民,正在雅鲁藏布江边辛苦劳作.\n");
	set("combat_exp", 100+100*random(10));
	set("chat_chance", 15);
	set("chat_msg", ({
		"陌生人说道：唉....日子越来越不好过罗。\n",
		(: random_move :)
	}) );
	set("env/wimpy", 10);
	setup();
	carry_object(__DIR__"obj/zcloth")->wear();
}
