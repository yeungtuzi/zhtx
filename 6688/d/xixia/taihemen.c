// Room: /d/xixia/taihemen.c

inherit ROOM;

void create()
{
	set("short", "太和门");
	set("long", @LONG
太和门又叫皇极门，是宫殿的大朝门，前面你看到了一个
正方形的广阔而开朗的院落，两侧崇楼高阁，正中巍然屹立于
须弥座台上的正是太和殿。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiwei3" : 2,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuyingdian",
  "north" : __DIR__"taihedian",
  "south" : __DIR__"ebridge",
  "west" : __DIR__"wenhuadian",
]));

	setup();
	replace_program(ROOM);
}
