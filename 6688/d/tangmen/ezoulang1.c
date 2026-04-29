// Room: /d/tangmen/ezoulang1.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "东走廊");
        	set("long", @LONG
这里是东走廊，南边是厨房，不时的飘来饭菜的香味。
LONG
        		);
        	set("exits", ([ /* sizeof() == 2*/
  		"west"   : __DIR__"guodao",  
		"east"  : __DIR__"ezoulang2", 
		"south" : __DIR__"chufang",
		]));
	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

