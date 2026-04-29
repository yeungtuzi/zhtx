// Room: /d/tangmen/road1.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "山道");
        	set("long", @LONG
你走在崎岖的山道小路上，道旁的小草稀稀落落。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2 */
  		"west" 		: __DIR__"road2",
  		"northeast" 	: "/d/road/rcdtojs0",
		]));
        	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

