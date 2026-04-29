// Room: /d/tangmen/room1.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "唐剑书房");
        	set("long", @LONG
这里是少门主唐剑的书房，平时唐剑在此会见熟人。房里只有几排书架。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"south"  : __DIR__"wzoulang2",  
		]));

        	setup();
        	replace_program(ROOM);
}

