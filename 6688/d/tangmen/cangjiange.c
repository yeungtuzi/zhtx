// Room: /d/tangmen/cangjiange.c         
//writen by tang

inherit ROOM;

void create()
{
        	set("short", "藏剑阁");
        	set("long", @LONG
    这里就是藏剑阁了，四周什么也没有，你走来走去，到处寻找机关，
但是什么也没有发现，只听见“咚咚”的声音，就好象走在鼓面上似的。
LONG
        		);
        	set("exits", ([ /* sizeof() == 1*/
  		"west"   : __DIR__"houhuayuan",  
		]));                                       

        	setup();

}

void init()
{           
	add_action("do_knock","knock");
	add_action("do_uncover","uncover");
}         

 int do_knock()
{
                tell_object(this_player(), "你敲了敲地板，传来“咚咚”的声音，看来地板是空的，可以把它揭开。\n");
                return 1;
}

int do_uncover(string arg)
{
        	object me;
        	me = this_player();

	if( !arg )	              	return notify_fail("你要揭开什麽?\n");
        
        	if ( arg ="floor" || arg = "地板")
             	{
	 	message_vision( "\n$N把地板揭开，露出一条向下的小路。\n",me);
		set("exits/down",__DIR__"door");       
		remove_call_out("close");
		call_out("close",5);
        		return 1;
	}

} 
 
int close()
{
	delete("exits/down");
	tell_room("\n揭开的地板又自动合上了。\n");
	return 1;
}       
