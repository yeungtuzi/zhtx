// Room: /d/quanzhen/road2.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条驿道静静的向远方延伸，旁边车轮滚滚，不少行人走来走去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"road3.c",
		"north" : __DIR__"road1.c",
]));

	setup();
	replace_program(ROOM);
}
