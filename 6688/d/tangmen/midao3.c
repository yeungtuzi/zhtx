//藏剑阁密道
// written by tang

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
  藏剑阁密道，四周静悄悄的，墙上的油灯忽明忽灭。
LONG
	);

	set("exits", ([           
		"east" : __DIR__"mishi"+(random(17)+1),
		"south" : __DIR__"mishi"+(random(17)+1),
		"west" : __DIR__"mishi"+(random(17)+1),          
		"north" : __DIR__"midao4",
	]));

	setup();    
        	replace_program(ROOM);
}

