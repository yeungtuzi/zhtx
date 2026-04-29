// Room: /d/xixia/eroad3.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
这里是通向正殿的御道，地面上用红色地毯铺着，甚是华丽。道路
两旁旌旗招展，原来两边驻扎着六军六部。西边是前军都督府，东边则是
兵部。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"bingbu",
  "north" : __DIR__"eroad4",
  "south" : __DIR__"eroad2",
  "west" : __DIR__"barracks4",
]));

	setup();
	replace_program(ROOM);
}
