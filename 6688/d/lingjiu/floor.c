// Room: /d/lingjiu/floor.c

inherit ROOM;

void create()
{
	set("short", "演武场");
	set("long", @LONG
这是一块宽阔的演武场，灵鹫宫的弟子平时就在这里练武。场上的两侧
竖立兵器架，上面十八般武器，无一不有。往北通向灵鹫宫正厅，东边
是武器库，西边是护具库。
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
  "out" : __DIR__"gate",
  "north" : __DIR__"path0",
  "east" : __DIR__"eastroom",
  "west" : __DIR__"westroom",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
