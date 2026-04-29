// Room: /d/hua/garden.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是典型的农家小院，养着鸡、鸭和猪，还种了点菜。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road",
  "south" : __DIR__"kitchen",
]));
	set("objects", ([
		__DIR__"npc/man": 1,
	]));
	set("resource/apparition", 100);
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
