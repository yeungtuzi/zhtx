// Room: /d/tangmen/room5.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "有为轩");    
        	set("long", @LONG
 这是唐门门主的书房。在正对门的墙上挂着一幅条幅，上书“有为轩”
三个大字。屋南端是一张书桌，上面堆满了唐诗宋词。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"east"  : __DIR__"wzoulang3",  
		]));

        	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me;
	
	me = this_player();

	if( !arg )
		return notify_fail("你要干什么？\n");
	
	if( arg != "table" && arg != "书桌" )
		return notify_fail("你要移什么？\n");

	message_vision("$N把书桌移到一边。\n",me);
	add("move",1);

	return 1;
}

