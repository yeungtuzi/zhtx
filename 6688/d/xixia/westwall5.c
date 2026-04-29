// Room: /d/xixia/westwall5.c

inherit ROOM;

void create()
{
	set("short", "西城墙");
	set("long", @LONG
整个城墙由一块块巨大的花岗岩石砌成，既宽敞又平坦。
两边的护墙高可及人肩，透过护墙间的垛口，里边是繁华的西
夏都城，外边则是一望无际的草原和荒漠。整个城墙被护城河
环绕着，固若金汤。城墙上你看到了许多士兵在巡逻，个个衣
甲鲜明，精神抖擞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"westwall7",
  "south" : __DIR__"westwall3",
]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/traveler": 1,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
