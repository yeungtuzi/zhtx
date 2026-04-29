// Room: /d/xixia/marketplace2.c

inherit ROOM;

void create()
{
	set("short", "榷场");
	set("long", @LONG
这里是供大家交换物品的场所，也就是市场，布帛，茶叶，
青盐，大米，牲畜都可以拿来这里交换。这里的榷场虽然也是
人来人往，但较中原之繁华，显见相差甚远，毕竟西夏辟处西
北荒凉之地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"northsquare",
]));
	set("objects", ([
		__DIR__"npc/woman": 1,
		__DIR__"npc/maid": 1,
	]));

	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
