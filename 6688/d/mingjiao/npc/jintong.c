
inherit NPC;

void create()
{
	set_name("小童", ({ "xiao tong" }) );
	set("gender", "男性" );
	set("age", 14);
	set("long",
		"一个天真无邪，未懂世事的小金童\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set_skill("unarmed",50);
	set_skill("dodge",50);
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
	switch( random(2) ) {
		case 0:
message_vision("$N看了$n一眼，然后捂住嘴开始＂吃吃＂的笑。\n",this_object(),ob);
			break;
		case 1:
			command("xixi");
	}
}
