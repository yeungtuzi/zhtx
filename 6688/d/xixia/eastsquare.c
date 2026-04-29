// Room: /d/xixia/eastsquare.c

inherit ROOM;

void create()
{
	set("short", "东门广场");
	set("long", @LONG
这里是一个方圆近十余丈的广场，四面八方的街道汇聚于此，使得
这里车水马龙，好不热闹。广场的西南角围着一群人，都伸长着脖子往
里看，不时还喝彩几声。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"eaststreet1",
  "north" : __DIR__"eaststreet5",
  "south" : __DIR__"eaststreet2",
  "west" : __DIR__"bankroom",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/father" : 1,
  __DIR__"npc/daughter" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
