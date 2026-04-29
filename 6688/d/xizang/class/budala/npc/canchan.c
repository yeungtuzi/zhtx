// d/xizang/class/budala/npc/canchan.c

inherit NPC;

void create()
{
	set_name("布达拉宫弟子", ({ "lama dizi", "dizi"}) );
	if(random(30)>21)
		set("gender", "女性" );
	else set("gender", "男性");

	set("age", 21+random(30));
	set("long", "一名正在领悟佛法的布达拉宫弟子\n");
	set("attitude", "peaceful");

        set("combat_exp", 1600+random(60)*200);
        create_family("布达拉宫", random(4)+14, "弟子");
        set_skill("unarmed", 25+random(50));
        set_skill("force", 40+random(50));
	set_skill("zang-buddhi", 20+random(50));
	setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}
