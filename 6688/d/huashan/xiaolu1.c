//小路
//
inherit ROOM;
void create()
{
	set("short","小路");
	set("long",
@LONG
一条弯弯曲曲的小路，顺着山谷向南延伸进山里面去。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southeast"  : __DIR__"xiaolu2",
		"north": "/d/village/eexit",
		
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

