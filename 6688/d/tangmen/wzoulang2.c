// Room: /d/tangmen/wzoulang2.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "西走廊");
        	set("long", @LONG
这里是西走廊，两边是少门主的书房。北面是唐剑的书房，南面是\n
是唐白的书房。
LONG
        		);
        	set("exits", ([ /* sizeof() == 4*/
  		"east"   : __DIR__"wzoulang1",  
		"west"  : __DIR__"wzoulang3",
		"north"  : __DIR__"room1",
		"south" : __DIR__"room2",
		]));
        	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

