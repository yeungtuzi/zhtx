// Room: /d/tangmen/pavilion.c         
//writen by tang

inherit ROOM;

void close_men();

void create()
{
        set("short", "亭子");
        set("long", @LONG
    这里是乘凉的亭子，亭子的中央有一张大石桌，东边是一个
荷塘，夏天，荷塘里的荷花散发出沁人心脾的清香，唐门子弟经
常在这聚会，中秋节时，唐门门主会和大家一起在这赏月。
LONG
        		);
        set("exits", ([ /* sizeof() == 1*/
  		"south"   : __DIR__"houhuayuan",  
		]));                         
        set("outdoors", "tangmen");

        setup();

}

void init()
{
	add_action("do_turn","turn");
}

int do_turn(string arg)
{
	int i,n;
	object me,*ob,room;

    	if (query("exits/down"))
        	return notify_fail("机关已经触发啦。\n");

	if( !arg ) 	return notify_fail("你要干什么？\n");
	if( arg=="table" || arg=="石桌" )
	{
		me=this_player();
		message_vision("$N不小心触动了机关，亭子里顿时暗器横飞。\n",me);

		ob=all_inventory(environment(me));
		n=sizeof(ob);
		while( n-- )
			if( userp(ob[i]) )	i++;
		while( i-- )
		{
			if( userp(ob[i]) )
			{
				if( ob[i]->query_skill("dodge") < 100 )
				{
					tell_object(ob[i],"你躲闪不及，一枚暗器穿胸而过。\n");
					ob[i]->receive_wound("kee",100);
				}
				else
				{
					tell_object(ob[i],"你纵高伏低，左躲右闪，躲过了大部分暗器，只有一枚暗器射在了左肩上。\n");
					ob[i]->receive_wound("kee",10);
				}
			}
		}

	    	if(!(room = find_object(__DIR__"room5")))
        		room = load_object(__DIR__"room5");

		if( room->query("move") % 2 == 0 )	return 1;
		
		message_vision("暗器过后，地上露出了一个黑忽忽的大洞。\n",me);

	    	if(!(room = find_object(__DIR__"didao1")))
        		room = load_object(__DIR__"didao1");
        
	    	set("exits/down", __DIR__"didao1");

        	room->set("exits/up", __FILE__);
		message("vision", "有人从外面把机关打开啦。\n", room);
        	remove_call_out("close_men");
        	call_out("close_men", 5);
	
		return 1;
	}

} 
 
void close_men()
{
    	object room;

	if( !( room = find_object(__DIR__"didao1")) )
	        room = load_object(__DIR__"didao1");
    	if(objectp(room))
	{
		delete("exits/down");
		message("vision", "地上的大洞又自动合上了。\n", this_object());
		room->delete("exits/up");
		message("vision", "顶上的大洞又自动合上了。\n", room);
	}
    	else message("vision", "ERROR: men not found(close).\n", room);
}

