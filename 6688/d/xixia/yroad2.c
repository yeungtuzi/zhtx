// Room: /d/xixia/yroad2.c

inherit ROOM;

void create()
{
	set("short", "花园小径");
	set("long", @LONG
小径弯弯曲曲，透过前面花草掩映之中你看到了楼阁的一角，
阁边挑出两盏宫灯。在这花园深处居然还有这么一座楼阁，你不禁
心中一喜。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pmaid" : 2,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"qingfengge",
  "north" : __DIR__"yroad1",
]));

	setup();
	replace_program(ROOM);
}
