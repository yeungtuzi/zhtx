// Room: /d/tangmen/lianwuchang.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "练武场");
        	set("long", @LONG
这是唐门的练武场，地上散落着石锁，石担之类的东西，唐剑正在督导\n
五六代弟子练功。东面是武器库，北面是后花园。
LONG
        		);
        	set("exits", ([ /* sizeof() == 3*/
  		"west"   : __DIR__"ezoulang2",  
		"east"   : __DIR__"wuqiku",
		"north"  : __DIR__"houhuayuan",
		]));                                       
	set("objects",([                                                            
		__DIR__"npc/dizi3"	: 2,
		__DIR__"npc/dizi2"	: 2,
		CLASS_D("tangmen")+"/tangjian"  :	1,
		]));
        	set("outdoors", "tangmen");

        	setup();

}
