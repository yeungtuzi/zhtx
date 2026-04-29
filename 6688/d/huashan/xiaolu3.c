//小路
//
inherit ROOM;
void create()
{
	set("short","小路");
	set("long",
@LONG
一条弯弯曲曲的小路，顺着山谷向南延伸进山里面去。再往前看，就可以
看见有块很大的空地，那就是青柯坪了。
LONG);
         set("exits", ([ /* sizeof() == 2 */
		"southwest"  : __DIR__"qingkeping",
		"north": __DIR__"xiaolu2",
		]));
	set("outdoors","huashan");	 
	setup();
	replace_program(ROOM);
}

