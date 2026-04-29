
inherit ROOM;

void create()
{
	set("short", "沙漠");
	set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。
看来要走出这块沙漠并非易事。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
//	"west" : "/d/xingxiu/btshan",
	"east" : "/d/road/dunhuang",
	"north": "/d/road/dhshamo",
	"south": "/d/road/dhshamo",
]));

	set("objects", ([
		__DIR__"npc/snake.c":2,
	]) );
	setup();
	replace_program(ROOM);
}
