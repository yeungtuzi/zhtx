// waiter.c
// a cool one!

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(HIW"店小二"NOR, ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 24);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");

	set("combat_exp", 150000);
	set("max_force", 1500);
	set("force", 2000);
	set("force_factor", 75);

	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		__DIR__"obj/nuomi": 1,
		__DIR__"obj/xigua": 1,
		"/obj/example/wineskin": -1,
		"/obj/example/dumpling": -1,
		"/obj/example/chicken_leg": -1,
	]) );

	set_temp("apply/damage", 80);
	set_temp("apply/armor", 50);
	set_temp("apply/armor_vs_force", 50);

	set_skill("force", 100);
	set_skill("whip", 30);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("move", 100);
	set_skill("banruo-zhang",150);
	set_skill("strike",100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("riyue-bian", 180);
	set_skill("shaolin-shenfa", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("move", "shaolin-shenfa");
	map_skill("strike","banruo-zhang");
	
	prepare_skill("strike","banruo-zhang");

	setup();
	carry_object("/obj/cloth")->wear();
	carry_object(__DIR__"obj/maojin")->wield();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
	add_action("do_look", "look");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的红酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}

int do_look(string arg)
{
	if (arg == "waiter") {
		set("env/attack", 1);
		set("force_factor", 0);
		set("force", 0);
		set("max_force", 0);
		set("combat_exp", 0);
		set_temp("apply/damage", 0);
		"/cmds/std/look"->look_living(this_player(), this_object());
		set("env/attack", 50);
		set("force_factor", 75);
		set("force", 2000);
		set("max_force", 1500);
		set("combat_exp", 150000);
		set_temp("apply/damage", 80);
		return 1;
	}
}
