// Room: /d/lingjiu/mi2.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是一个巨大的石窟，连接着两边的地道，可见整个地道是依着
山腹中天然的洞穴而开成。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"mi3",
  "south" : __DIR__"mi1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
