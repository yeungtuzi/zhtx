// Room: /d/lingjiu/cliff.c

inherit ROOM;

void create()
{
	set("short", "断魂崖");
	set("long", @LONG
这里就是缥缈峰的“十三景之一”断魂崖，所谓“断魂”，故名思义，
从这里掉下去，当真是魄散魂断！回头下望，山下已如蚁蛭，山势笔陡，
你心中不禁害怕起来。左右两边再走几十米皆是万丈深渊，前面你看到
一条岩石路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rock",
  "south" : __DIR__"pm",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
