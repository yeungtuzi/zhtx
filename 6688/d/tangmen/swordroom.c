//藏剑阁剑室
// written by tang

inherit ROOM;

void create()
{
	set("short", "剑室");
	set("long", @LONG
  这里是藏剑阁剑室，四周空荡荡的，什么也没有，半空中悬着一根横梁。
LONG
	);

	set("exits", ([           
		"east" : __DIR__"midao4",
	]));

	setup();    

}
                                                                                                              
void init()
{
	add_action("do_jump","jump");
}
                                                        
int do_jump(string arg)
{
	if( arg=="梁" || arg=="横梁" )
	{
		if( this_player()->query("combat_exp")<100000 )
		{
			message_vision("$N跳上横梁, 但脚下一滑, 从横梁上掉了下来!\n",this_player());
			return 1;
		}
		this_player()->move(__DIR__"liang");
		return 1;
	}
	tell_object(this_player(),"你要跳到哪？\n");
	return 1;
}
