//小路
//
inherit ROOM;
void create()
{
	set("short","小路");
	set("long",
@LONG
一条弯弯曲曲的小路，顺着山谷向南延伸，已经开始向下走了。
西边已经能看见西岳庙的濪灵门了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"lingmen",
		"northwest": __DIR__"xiaolu4",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

