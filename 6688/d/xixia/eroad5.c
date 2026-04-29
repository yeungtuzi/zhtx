// Room: /d/xixia/eroad5.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
这里是通向正殿的御道，地面上用红色地毯铺着，甚是华丽。道路
两旁旌旗招展，原来两边驻扎着六军六部。西边是左军都督府，东边则
是户部。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiwei8" : 1,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"hubu",
  "north" : __DIR__"eroad6",
  "south" : __DIR__"eroad4",
  "west" : __DIR__"barracks2",
]));

	setup();
	replace_program(ROOM);
}
