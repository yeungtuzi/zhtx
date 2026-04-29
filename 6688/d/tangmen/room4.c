// Room: /d/tangmen/room4.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "唐圆闺房");
        	set("long", @LONG
这里是唐云二女儿唐圆的居所，屋中摆设很少，只有一桌、一椅、
一床、一几，一个漂亮的姑娘正坐在桌子前看书。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"north"  : __DIR__"wzoulang3",  
		]));                                        
	set("objects",([
		__DIR__"npc/tangyuan"	: 1,
		]));

        	setup();
        	replace_program(ROOM);
}

