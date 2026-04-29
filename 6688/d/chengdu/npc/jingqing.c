
inherit NPC;

void create()
{
	set_name("静清师太", ({ "jingqing shitai","shitai","jingqing" }));
	set("gender", "女性");
	set("age", 40);
	set("str", 25);
	set("dex", 30);
	set("long", "她是峨嵋派第四代弟子，下山来主持妙香庵的烟火。\n");
	set("combat_exp", 600000);
	set("shen_type", 1000);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);

	setup();
}

