// Room: /d/tangmen/room2.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "唐白书房");
        	set("long", @LONG
这里是少门主唐白的书房，平时唐白在此会见熟人。房里只有几排书架。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"north"  : __DIR__"wzoulang2",  
		]));                       
	set("objects",([
		__DIR__"npc/tangbai": 1,
		]));

        	setup();
        	replace_program(ROOM);
}

