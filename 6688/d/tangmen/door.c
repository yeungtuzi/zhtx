// Room: /d/tangmen/door.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "铁门");
        	set("long", @LONG
  一扇结实的大铁门，门上有一个钥匙孔。	
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"up"   : __DIR__"cangjiange",  
		]));                                       

        	setup();
}

void init()
{           
	add_action("do_unlock","unlock");
}         

 int do_unlock()
{                                                                        
	object ob;

	if( !this_player()->query_temp("marks/changsheng-ok") )
	return notify_fail("这钥匙你不会用!\n");
	
	if( (ob=present("key",this_player())) )     
	{
                message_vision("$N掏出钥匙，打开铁门，只听“啪”的一声，钥匙断了\n
			$N毫不犹豫地走了进去!\n",this_player());
		this_player()->move(__DIR__"midao");  
		destruct(ob);                         
		return 1;
	}
	return 0;
}
