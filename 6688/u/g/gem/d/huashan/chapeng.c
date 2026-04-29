//chapeng.c 茶棚
//by emote
inherit ROOM;

void create()
{
	set("short","小茶棚");
	set("long",
@LONG
这里已经快到华山的北峰了，居然在这里有一个小茶棚，很是令人诧异
而且小茶棚的老板竟然是一位美貌女子，这不能不更让人诧异。现在，小茶
棚里面没有几个人，除了几个江湖豪客之外就没什么别人了。女老板正做在
茶棚外招呼过往客人。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"laojungou",
		
]));
        set("objects", ([
                 __DIR__"npc/fox":1,
                 __DIR__"npc/easts":1,                 
		 __DIR__"npc/haoke":2,
]));



	setup();
	replace_program(ROOM);
}

