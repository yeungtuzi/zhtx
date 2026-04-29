// Room: /d/hua/road1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条被人踩出的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road2",
  "west" : __DIR__"road",
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

