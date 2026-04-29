
inherit ROOM;

void create()
{
	set("short", "平台");
	set("long", @LONG
	这里是林忌平时炼丹修行的静室，平时从未有弟子被允许进来。	
LONG
	);
	set("no_fight",1);
	setup();
}

void init()
{
	add_action("do_burn","conjure");
	add_action("do_burn","burn");
	add_action("do_quit", "quit");
}

int do_burn(string arg)
{
	write("这里施法会带来不可预料的后果，你确定吗？\n");
	return 1;
}

int do_quit(string arg)
{
	if(!present("master taolord",this_object()))
	{
		message_vision("$N试图离开，墙上的八卦突然旋转起来，$N顿时一阵天旋地转...\n",this_player());
		this_player()->move("/d/moyu/valley/shidao3");
		tell_room(this_object(),this_player()->query("name")+"身影渐渐隐去。\n");
		return 1;
	}

	write("现在想逃？晚了！\n");
	return 1;
}
