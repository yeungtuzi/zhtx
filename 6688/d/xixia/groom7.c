// Room: /d/xixia/groom7.c

inherit ROOM;

void create()
{
	set("short", "赫连铁树书房");
	set("long", @LONG
四周一遍漆黑，什么也看不清楚。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"ggroom6",
]));
	set("objects", ([
		__DIR__"npc/murongbo": 1,
	]));

	setup();
}

void init()
{
        add_action("do_quit", "quit");
}

int do_quit(string arg)
{
        write("一走了之？\n");
        return 1;
}

int valid_leave(object me, string dir)
{
	if (present("murong bo") || present("yiping fighter"))
		return notify_fail("想逃？没门！\n");
        return ::valid_leave(me, dir);
}
