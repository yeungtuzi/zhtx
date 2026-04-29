// Room: /d/xixia/ygate.c

inherit ROOM;

void create()
{
	set("short", "山洞门前");
	set("long", @LONG
好容易穿过竹林，呈现在你眼前的是一座高山，山前面开了一
个洞门，不知道该当进去与否？
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ymaid" : 4,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bamboo1",
  "enter" : __DIR__"yongdao",
]));

	setup();
	replace_program(ROOM);
}
