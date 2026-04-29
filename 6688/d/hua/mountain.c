// Room: /d/hua/mountain.c

inherit ROOM;

void create()
{
	set("short", "大山");
	set("long", @LONG
这座大山由于常有野兽出没，已经没什么人敢来了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"road",
]));
	set("objects", ([
		__DIR__"npc/tiger" : 1,
	]));

	setup();
}

void init()
{
	add_action("no_quit", "quit");
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
