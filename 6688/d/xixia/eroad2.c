// Room: /d/xixia/eroad2.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
这里是通向正殿的御道，地面上用红色地毯铺着，甚是华丽。道路
两旁旌旗招展，原来两边驻扎着六军六部。西边是后军都督府，东边则
是刑部。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/young" : 1,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"xingbu",
  "north" : __DIR__"eroad3",
  "south" : __DIR__"eroad1",
  "west" : __DIR__"barracks5",
]));

	setup();
	replace_program(ROOM);
}
