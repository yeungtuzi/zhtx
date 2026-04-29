// Room: /d/tangmen/room3.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "唐方闺房");
        	set("long", @LONG
这里是唐云大女儿唐方的居所，屋中摆设很少，只有一桌、一椅、
一床、一几，一个漂亮的姑娘正坐在桌子前写信。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"south"  : __DIR__"wzoulang3",  
		]));                
	set("objects",([
		CLASS_D("tangmen")+"/tangfang"	: 1,
		]));

        	setup();
        	replace_program(ROOM);
}

