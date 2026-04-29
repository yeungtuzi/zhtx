// Room: /d/xixia/smithroom.c

inherit ROOM;

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
走进铁匠铺，一股热气扑面而来，只见左边不远处一个
中年汉子，不停地挥舞着铁锤，不知道在打造什么兵器？铺
子墙壁上则挂满了各式各样的兵器，闪闪发光。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"northstreet2",
]));
	set("objects", ([
		__DIR__"npc/smith": 1,
	]));

	setup();
	replace_program(ROOM);
}
