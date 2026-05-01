// keeper.c

inherit NPC;

void create()
{
	set_name("法师", ({ "keeper" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long",
		"这个法师看起来四十多岁了，嘴里不知念着什么经文。\n");
	set("combat_exp", 1);
	set("attitude", "friendly");
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
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "法师说道：这位" + RANK_D->query_respect(ob)
		+ "，捐点香火钱积点阴德吧。\n");
}

int accept_object(object who, object ob)
{
	say( "法师说道：这位" + RANK_D->query_respect(who)
		+ "，请把香油钱投入功德箱。\n");
	return 0;
}
