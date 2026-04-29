
#include <ansi.h>

inherit NPC;
void create()
{
	int i,amun;
        string *name= ({"侍剑", "司棋", "紫娟", "聆琴", "听雨"});
	set_name( name[random(5)] , ({ "pretty girl", "girl" }) );
	set("long", "这是一位山谷中的小丫头，也不知道是谁家的姑娘。\n");
	set("attitude", "friendly");
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 13);
        set("gender", "女性" );
        set("chat_chance", 1);
        set("chat_msg", ({
                "小丫头窃窃道：听说瀑布后面经常有鬼影出没...\n",
        }) );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);

	set("combat_exp", 50000);
	set_skill("throwing",250+random(100));
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/anqi")->wield();
}
