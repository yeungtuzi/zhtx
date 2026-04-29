// Room: /d/xixia/eroad8.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
这里御道两旁是六科值班，用来辅助皇帝处理奏章，同时检查
和监督六军六部等机构。往北通向午门。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wumen",
  "south" : __DIR__"duanmen",
]));

	setup();
	replace_program(ROOM);
}
