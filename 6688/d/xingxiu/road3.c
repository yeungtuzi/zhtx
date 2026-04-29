// Room: /d/xingxiu/road3.c

inherit ROOM;

void create()
{
	set("short", "小道");
	set("long", @LONG
一条僻静的小道，两旁是杂草灌木。小道尽头是一个山洞,但是被一块巨岩堵死了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
//  "enter" : __DIR__"prison",
  "west" : __DIR__"road2",
]));
	set("objects", ([
		__DIR__"npc/chuchen" : 1,
]));
	set("outdoors", "xingxiu");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object me = this_player();

	if( arg != "rock" && arg != "岩石" )
		return notify_fail("你要搬动什么东东？\n");

	if( !present("chuchen zi", environment(me)) ){
		if( me->query_str() < 32 )
			return notify_fail("你使出吃奶的力也搬不动岩石。\n");
		else{
			message_vision("$N把岩石挪到一旁，露出一个洞口来。\n", me);
			environment(me)->set("exits/enter", __DIR__"prison");
			return 1;
		}
	}
	else{
		if( me->query("mark/ding_chushi") != 1 )
			return notify_fail("出尘子对你怒目而视。\n");
		else{
			message_vision("出尘子对$N说道：“"+me->query("gender") == "女性"? "大师姐":"大师兄"+"是要进洞去看看吧！”千万不可让老仙知道了。\n", me);
			message_vision("说完，出尘子替$N把岩石挪到一旁，然后恭恭敬敬地一旁侍候。\n", me);
			environment(me)->set("exits/enter", __DIR__"prison");
			return 1;
		}
	}
}

	
		
