// zyl3.c
// By Tang 

inherit ROOM;

void close_men();

void create()
{
	    set("short", "紫阳楼三楼");
	    set("long", @LONG
这是紫阳楼的三楼，专门承办酒席，举行婚礼的地方，许多的武林人物聚集
在这里，正在给一对新人祝贺，紫阳楼的老板扮作赞礼官，新郎与新娘的朋
友作伴郎与伴娘，中间打扮得很漂亮的就是新郎与新娘啦，大家正在给他们
灌酒。北边有一扇门（men），好象是虚掩着，里面是洞房。
LONG
    );
                                                       
	set("no_fight", 1);
	set("no_magic", 1);
	set("exits", ([
		"down" : __DIR__"zyl2",
	    ]));
                                                    
	setup();
}

void init()
{
    	add_action("do_push", "push");
}

void close_men()
{
    	object room;

	if( !( room = find_object(__DIR__"dongfang")) )
	        	room = load_object(__DIR__"dongfang");
    	if(objectp(room))
	{
		delete("exits/enter");
		message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
		room->delete("exits/out");
		message("vision", "门吱吱呀呀地自己合上了。\n", room);
	}
    	else message("vision", "ERROR: men not found(close).\n", room);
}

int do_push(string arg)
{
    	object room;

	if( !this_player()->query_temp("enter") )
		return notify_fail("你要干什么？\n");

    	if (query("exits/enter"))
        		return notify_fail("门已经是开着了。\n");

    	if (!arg || (arg != "door" && arg != "men"))
        		return notify_fail("你要推什么？\n");

    	if(!(room = find_object(__DIR__"dongfang")))
        		room = load_object(__DIR__"dongfang");
        
    	set("exits/enter", __DIR__"dongfang");
        	message_vision("$N轻轻地把门推开。\n", this_player());
        	room->set("exits/out", __FILE__);
	message("vision", "有人从外面把门推开了。\n", room);
        	remove_call_out("close_men");
        	call_out("close_men", 10);
	
	return 1;
}

int valid_leave(object me, string dir)
{
    	object room;
    	
	if(!( room = find_object(__DIR__"dongfang")) )
	        	room = load_object(__DIR__"dongfang");

	if(objectp(room) && dir == "enter")
	{
		if( !me->query_temp("enter") )
			return notify_fail("你不是新人，不能进去。\n");
		return ::valid_leave(me, dir);
	}		

	return ::valid_leave(me, dir);
}

