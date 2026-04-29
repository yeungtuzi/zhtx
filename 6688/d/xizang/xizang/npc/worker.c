// /d/xizang/npc/worker.c

inherit NPC;

void create()
{
	set_name("采石工", ({ "worker" }) );
	set("gender", "男性" );
	set("age", 25+random(16));
	set("long", 
"你看到一个粗壮的大汉，身上穿著简单的衣服，正在忙着修整采下的石料。\n");
	set("combat_exp", 100+100*random(10));
	set("str", 33);
	set("chat_chance", 15);
	set("chat_msg", ({
		"采石工说道：唉....累死了....\n",
	}) );
	set("env/wimpy", 10);
	set_skill("hammer", 10+random(10));
	setup();
	carry_object(OBJ_DIR"weapon/hammer")->wield();
	carry_object(OBJ_DIR"cloth")->wear();
}
