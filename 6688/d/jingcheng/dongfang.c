// dongfang.c
// Tang

inherit ROOM;

void close_men();

void create()
{
    	set("short", "洞房");
        	set("long", @LONG
        这是一间收拾整洁的厢房，门和窗关闭着，房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，上面放着大红的锦被，
一对绣着鸳鸯戏水的粉红枕头放在一头，琉璃帐子配金挂钩显得
煞是好看，在床旁边的桌子上，点着一对红烛，烛光将房间映得
分外艳，红烛旁放着一壶酒和两个玉做的酒杯，

LONG
        );
                                                                
	set("objects", ([
		__DIR__"npc/obj/bosijiu.c": 1]));

        	set("sleep_room", 1);
        	set("no_fight", 1);

        	setup();
}


void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_men()
{
	object room;

	if(!( room = find_object(__DIR__"zyl3")) )
		room = load_object(__DIR__"zyl3");
	if(objectp(room))
	{
		delete("exits/out");
		message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
		room->delete("exits/enter");
		message("vision", "门吱吱呀呀地自己合上了。\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/out"))
		return notify_fail("门已经是关着的了。\n");

	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要关什么？\n");

	message_vision("$N想把门关上。\n", this_player());

	remove_call_out("close_men");
	call_out("close_men", 1);

	return 1;
}

int do_open(string arg)
{
	object room;
	object me = this_player();

	if (query("exits/out"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "men" && arg != "door"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"zyl3")) )
		room = load_object(__DIR__"zyl3");
	if(objectp(room))
	{
		set("exits/out", __DIR__"zyl3");
		message_vision("$N轻手轻脚地把门打开。\n", this_player());
		room->set("exits/enter", __FILE__);
		
		if (me->query_temp("sleeped"))
		{
		message("vision", "吱地一声，"+me->query("name")+"精神焕发地从里面把门打开了。\n", room);
		} 
		
		remove_call_out("close_men");
		call_out("close_men", 10);
	}

	return 1;
}


