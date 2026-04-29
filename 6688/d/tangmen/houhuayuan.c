// Room: /d/tangmen/houhuayuan.c         
//writen by tang

inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
    这是唐门的后花园，花圃里种着芍药、牡丹、月季、蔷薇，还有一些
你叫不上名字的花儿，苗圃里种着一些奇怪的植物，散发出刺鼻的味道。
有两个十来岁的小孩在追逐打闹。
LONG
        		);
        set("exits", ([ /* sizeof() == 3*/
  		"south"   : __DIR__"lianwuchang",  
		"east"   : __DIR__"cangjiange",
		"north"	: __DIR__"pavilion",
		]));                                       
	set("objects",([                                                            
		__DIR__"npc/tangmei"	: 1,
		__DIR__"npc/tangzhu"	: 1,
		]));	
        set("outdoors", "tangmen");

        setup();
        replace_program(ROOM);
}
