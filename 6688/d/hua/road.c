// Room: /d/hua/road.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条奇曲山路，北面是一座大山，向东有条小路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"garden",
  "east" : __DIR__"road1",
  "west" : __DIR__"villige",
  "northup" : __DIR__"mountain",
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
