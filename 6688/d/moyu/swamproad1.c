//swamproad1.c
//by meteoric

inherit "/ldg/std/doom.c";

void create()
{
	set("short", "雪地小路");
	set("long", @LONG
这儿已经是雪原边缘，雪融化后使得路上泥泞不堪。路边杂草丛生，在寒风中显示
其顽强的生命力，再往前走就进入了一片沼泽地，据说从没人走出过那里。
LONG
	);
	set("exits", ([
		"eastdown":__DIR__"swamproad2",
		"westup"  :__DIR__"xueyuan/toswamp",
	]));
	setup();
}
