// Room: /d/xixia/yroad1.c

inherit ROOM;

void create()
{
	set("short", "花园小径");
	set("long", @LONG
小径曲曲折折，错综复杂，你都不知身在何处，唯有两旁
假山池沼、花草树木，观之不尽。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/muwanqing" : 1,
  __DIR__"npc/fly" : 2,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"egarden",
  "south" : __DIR__"yroad2",
]));

	setup();
	replace_program(ROOM);
}
