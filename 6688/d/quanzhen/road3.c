// Room: /d/quanzhen/road3.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
一条驿道静静的向远方延伸，旁边车轮滚滚，不少行人走来走去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"road2.c",
		"southup" : __DIR__"shijie1.c",
]));

	setup();
	replace_program(ROOM);
}
