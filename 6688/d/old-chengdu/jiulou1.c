
inherit ROOM;

void create()
{
	set("short", "散花楼");
	set("long", @LONG
	方圆数百里内提起散花楼可以说是无人不知，无人不晓。楼
下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去
了。楼上是雅座，散花楼大师傅的川菜手艺远近驰名。
LONG
	);
        set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"jiulou2",
		"south" : __DIR__"dongdajie1",
	]));

	set("objects", ([
		__DIR__"npc/waiter" : 1,
	]));

	setup();
	replace_program(ROOM);
}

