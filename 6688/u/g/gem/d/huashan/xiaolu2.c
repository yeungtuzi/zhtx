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
		"south"  : __DIR__"xiaolu3",
		"northwest": __DIR__"xiaolu1",
		"north" : "/d/road/rtgtoca1",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

