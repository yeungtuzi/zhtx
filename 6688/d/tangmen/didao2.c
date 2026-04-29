// Room: /d/tangmen/didao2.c         
//writen by tang

inherit ROOM;

void close_men();

void create()
{
        set("short", "秘室");
        set("long", @LONG
    这里湿漉漉的，好象是在水底下一样。在一面墙壁上刻着几个
大字：“琴瑟琵琶，八大王一般头面”。看来是需要你回答问题。
LONG
        		);
	set("total",50000);
	set("objects",([                                                            
		__DIR__"obj/throw_book2"	: 1,
		]));	              

        setup();

}

void init()
{
	add_action("do_write","write");
	add_action("do_write","answer");
}

int do_write(string arg)
{
	object me,room;

    	if (query("exits/east"))
        	return notify_fail("机关已经触发啦。\n");

	me=this_player();
	if( !arg )
	{
		tell_object(me,"你要干什么？\n");
		return 1;
	}

	if( arg != "魑魅魍魉，四小鬼各自肚肠" )
	{
		message_vision("$N用手在墙上无聊地划着。\n",me);
		return 1;
	}

	message_vision("$N不小心触动了机关，传来“轰隆窿”的声音。\n",me);

	message_vision("不久，东边的墙壁露出了一道小门。\n",me);

    	if(!(room = find_object(__DIR__"didao3")))
       		room = load_object(__DIR__"didao3");
        
    	set("exits/east", __DIR__"didao3");

       	room->set("exits/west", __FILE__);
	message("vision", "有人从外面把机关打开啦。\n", room);
       	remove_call_out("close_men");
       	call_out("close_men", 5);
	
	return 1;
} 
 
void close_men()
{
    	object room;

	if( !( room = find_object(__DIR__"didao3")) )
	        room = load_object(__DIR__"didao3");
    	if(objectp(room))
	{
		delete("exits/east");
		message("vision", "东边的小门又自动合上了。\n", this_object());
		room->delete("exits/west");
		message("vision", "西边的小门又自动合上了。\n", room);
	}
    	else message("vision", "ERROR: men not found(close).\n", room);
}

