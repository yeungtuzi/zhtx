// Room: /d/tangmen/ezoulang2.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "东走廊");
        	set("long", @LONG
这里是东走廊，东边是练武场，不时传来呼喝之声。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2*/
  		"east"   : __DIR__"lianwuchang",  
		"west"  : __DIR__"ezoulang1",
		]));
        	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

