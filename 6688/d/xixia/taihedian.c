// Room: /d/xixia/taihedian.c

inherit ROOM;

void create()
{
	set("short", "太和殿");
	set("long", @LONG
太和殿又叫金銮宝殿，是皇帝朝见文武百官的地方。殿内金
碧辉煌，气势凝重，殿前中间丹犀下面斜铺巨石雕刻的御道，两旁
是铜制的品级山，正是文武百官朝见皇帝之所在。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihemen",
  "north" : __DIR__"zhonghedian",
]));
	set("objects", ([
		__DIR__"npc/pgeneral": 2,
	]));

	setup();
	replace_program(ROOM);
}
