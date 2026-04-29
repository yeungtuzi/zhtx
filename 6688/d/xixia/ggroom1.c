// Room: /d/xixia/groom1.c

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
四周一遍漆黑，什么也看不清楚。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ggroom2",
]));

	set("objects", ([
		__DIR__"npc/gfighter2": 1,
		__DIR__"npc/tieshu": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (present("murong bo") || present("yiping fighter"))
		if (userp(me))
                	return notify_fail("想逃？没门！\n");
        return ::valid_leave(me, dir);
}
