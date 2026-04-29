// waiter.c

inherit NPC;

void create()
{
	set_name("店老头", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 62);
	set("long",
		"一位饱经沧桑的老头子。\n");
	set("combat_exp", 20000000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "店老头笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店老头用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店老头说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的红酒吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}
