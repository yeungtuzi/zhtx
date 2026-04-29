// JieYinShi
// pal 1997.05.11

#include "ansi.h"

inherit NPC;

string ask_for_join();
int 	do_join(string arg);

void create()
{
	set_name("接引使", ({"jieyin shi","jieyin","shi",}));
	set("long",
		"他是一位精明的中年人，身穿一件白布长袍。\n"
		"他正在上下打量着你。\n"
		);

	set("title", "明教" NOR);

	set("gender", "男性");
	set("attitude", "friendly");

	set("inquiry",([
		"明教"	: (: ask_for_join :),
		]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_kee", 450);
	set("max_gin", 200);
	set("force", 350);
	set("max_force", 350);
	set("force_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 50);
	set_skill("cuff", 50);
	set_skill("parry", 30);

	setup();

        carry_object(__DIR__"obj/baipao")->wear();
}
                  
void init()
{
	::init();
	add_action("do_join","join");
}
                  
string ask_for_join()
{
	return "你要加入我明教吗？\n";
}

int do_join(string arg)
{
	object me,ob;

	if(!arg || arg != "明教" ) return notify_fail("你要加入什么？\n");

	me = this_object () ;
	ob = this_player () ;

	if( ob->query("guild") == "明教" )
		return notify_fail("别捣乱了，快去练功吧。\n");

	if ( (string)ob->query("gender") == "女性" )
		command("chat 我明教又得一女中豪杰，真是可喜可贺 !");
	else 
		command("chat 我明教又得一英雄好汉，真是可喜可贺 !");

	ob->set("guild","明教");
	ob->set("title","明教教众"NOR);
	message_vision("接引使对$N说道：恭喜$N成为明教的一员！\n",ob);
	return 1;
}

