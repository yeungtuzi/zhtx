// Room: /d/xixia/eroad7.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
这里是通向宫内的必经之路。御道西边是社稷坛，东边是太庙，
往南经承天门可以出宫，往北到达端门。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taimiao",
  "north" : __DIR__"duanmen",
  "south" : __DIR__"chengtianmen",
  "west" : __DIR__"shejitan",
]));

	setup();
	replace_program(ROOM);
}
