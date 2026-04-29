//小路
//
inherit ROOM;
void create()
{
	set("short","小路");
	set("long",
@LONG
一条弯弯曲曲的小路，顺着山谷向南延伸，已经开始向下走了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southeast"  : __DIR__"xiaolu6",
		"northwest": __DIR__"xiaolu4",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

