// Room: /d/xingxiu/xxh3.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
小路继续蜿蜒前进，不远处可以看到一块较宽阔的平地。几个星宿弟子手里拿着一堆
鼓吹具，不知是何用意。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"xxh2",
  "northeast" : __DIR__"xxh4",
]));
	set("objects", ([
		__DIR__"npc/boshou" : 1,
		__DIR__"npc/gushou" : 1,
		__DIR__"npc/haoshou" : 1,
]));
	set("outdoors", "xingxiu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
