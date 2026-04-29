// Room: /class/qingcheng/shufang.c

inherit ROOM;

void create()
{
	set("short", "[35m书房[2;37;0m");
	set("long", @LONG
这里是余沧海的书房兼卧室。作为一个修道之人，他非常的注意自身的
修养，所以整个房间显得很干净利落。你都看不到这里有什么不对劲的地方
。要成为一代宗师，自然要从小事做起了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"guan1",
]));

	setup();
	replace_program(ROOM);
}
