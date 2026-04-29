// Room: /d/tangmen/guodao.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "西走廊");
        	set("long", @LONG
这里是西走廊，两边是两位小姐闺房。北面是唐方的闺房，南面是\n
是唐圆的闺房。
LONG
        		);
        	set("exits", ([ /* sizeof() == 4*/
  		"east"   : __DIR__"wzoulang2",  
		"west"  : __DIR__"room5",
		"north"  : __DIR__"room3",
		"south"  : __DIR__"room4",
		]));
        	set("outdoors", "tangmen");

        	setup();
        	replace_program(ROOM);
}

