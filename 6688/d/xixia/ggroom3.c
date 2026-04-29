// Room: /d/xixia/groom3.c

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
四周一遍漆黑，什么也看不清楚。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ggroom4",
  "south" : __DIR__"ggroom2",
]));

	set("objects", ([
		__DIR__"npc/gfighter": 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (present("murong bo") || present("yiping fighter"))
                return notify_fail("想逃？没门！\n");
        return ::valid_leave(me, dir);
}
