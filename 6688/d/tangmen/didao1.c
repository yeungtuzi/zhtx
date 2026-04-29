// Room: /d/tangmen/didao1.c         
//writen by tang

inherit ROOM;

void close_men();

void create()
{
        set("short", "秘室");
        set("long", @LONG
    这里湿漉漉的，四面的墙壁都是坚硬的花岗岩，即使用锋利的
斧子也只能在墙上砍出一道白印。
LONG
        		);
	set("total",50000);

        setup();

}

void init()
{
	add_action("do_drop","drop");
}

int do_drop(string arg)
{
	int i;
	object me,ob,room;

    	if (query("exits/east"))
        	return notify_fail("机关已经触发啦。\n");

	me=this_player();
	if( !arg || !(ob=present(arg,me)) )
	{
		tell_object(me,"你要干什么？\n");
		return 1;
	}

	if( ob->query_weight() < query("total") )
	{
		add("total",-(ob->query_weight()));
		return 0;
	}
	else
	{
		set("total",50000);
		message_vision("$N不小心触动了机关，传来“轰隆窿”的声音。\n",me);

		message_vision("不久，东边的墙壁露出了一道小门。\n",me);

	    	if(!(room = find_object(__DIR__"didao2")))
        		room = load_object(__DIR__"didao2");
        
	    	set("exits/east", __DIR__"didao2");

        	room->set("exits/west", __FILE__);
		message("vision", "有人从外面把机关打开啦。\n", room);
        	remove_call_out("close_men");
        	call_out("close_men", 5);
	
		return 0;
	}

} 
 
void close_men()
{
    	object room;

	if( !( room = find_object(__DIR__"didao2")) )
	        room = load_object(__DIR__"didao2");
    	if(objectp(room))
	{
		delete("exits/east");
		message("vision", "东边的小门又自动合上了。\n", this_object());
		room->delete("exits/west");
		message("vision", "西边的小门又自动合上了。\n", room);
	}
    	else message("vision", "ERROR: men not found(close).\n", room);
}

