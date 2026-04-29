// Room: /d/xixia/bank1.c

inherit ROOM;

void create()
{
	set("short", "深涧旁");
	set("long", @LONG
没想到，在这禁宫之中居然还有这么一条深涧，实令人匪夷所
思。除了涧旁点的四个明晃晃的火把，四处黑黝黝的。前方似乎已
然无路可走，不过定睛一看，有一根细细的钢丝横架涧上，就看你
有没有本事走过去了？
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ypath3",
  "west" : __DIR__"gangsi",
]));

	setup();
	replace_program(ROOM);
}
