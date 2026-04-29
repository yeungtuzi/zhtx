//藏剑阁密室
// written by tang

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间密室，墙上写着“二十四桥明月夜”几个大字。
LONG
	);

	set("exits", ([           
		"east" : __DIR__"mishi"+(random(17)+1),
		"south" : __DIR__"mishi"+(random(17)+1),
		"west" : __DIR__"mishi"+(random(17)+1),          
		"north" : __DIR__"midao",
	]));

	setup();
        	replace_program(ROOM);
}

