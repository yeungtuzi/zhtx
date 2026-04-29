// Room: /d/hua/kitchen.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
有一个硕大无比的操作台, 按红案白案分开, 
墙上挂满了板鸭、腊肉和一串串红辣椒, 
锅中正熬着鼋鱼蛋汤, 香气扑鼻, 令人口水直流。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden",
  "south" : __DIR__"restaurant",
]));
	set("no_fight", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/cook" : 1,
]));
	set("no_clean_up", 0);
	set("no_magic", 1);

	setup();
}

void init()
{
	add_action("no_quit", "quit");
	add_action("do_wash", "wash");
}

int no_quit()
{
	object me;
	me = this_player();
	if (me->query("marks/点菜")) {
		message_vision("$N刚想溜之大吉，但一想到还欠一屁股债就留下了。\n", me);
		return 1;
	}
	return 0;
}

int do_wash(string arg)
{
        object ob;
        object me;

	if (!arg || arg =="") {
		write("你要洗什么?\n");
		return 1;
	}
	if (arg != "plate" && arg != "bowl" &&
	    arg != "碗" && arg != "盘子" &&
	    arg != "盘") {
		write("这些东西不要洗。\n");
		return 1;
	}
        me = this_player();

	message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", me);
	me->add("gin",-30);
	me->add("sen",-30);
	ob = new("/obj/money/silver");
	ob->move(me);
	message_vision("老板娘对$N说：这是你的工钱。\n", me);
	return 1;
}
