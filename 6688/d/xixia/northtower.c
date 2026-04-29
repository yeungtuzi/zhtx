// Room: /d/xixia/northtower.c

inherit ROOM;

void create()
{
	set("short", "城楼");
	set("long", @LONG
走进城楼，首先映入眼帘的是那一排排武器架，上面插满了十
八般武器，刀枪剑戟，十分夺目。四周墙脚堆满了石头硫磺干柴等
物品，大概是守城用的。中间坐着几个巡逻士兵，稍做歇息。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"northwall1",
]));

	setup();
	replace_program(ROOM);
}
