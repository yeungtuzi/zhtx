// /d/xizang/mei_room.c

inherit ROOM;

void create()
{
        set("short", "小梅的房间");
        set("long", @LONG
这里是小梅的房间,整洁干净,弥漫着梅花的香气.
LONG
        );
//        set("no_fight", 1);
//        set("no_spells", 1);
//        set("no_magic", 1);
	set("no_die", 1);
	
	set("objects", ([
		__DIR__"npc/xiaomei" : 1
	]));
        setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, room;
	if (!arg || (arg=="")) return notify_fail("你要打开什么?\n");
	if ((arg!="door") && (arg!="门") && (arg!="south"))
		return notify_fail("这里没有" + arg +"可打开\n");
	me = this_player();
        if( query("exits/south") ) return notify_fail("门开着呢!\n");
	set("exits/south", __DIR__"in_cave");
        if( room = find_object(__DIR__"in_cave")){
                room->set("exits/north", __FILE__);
                message("vision","有人从里面打开了门.\n", room);
	}
	return 1;
	call_out("close_passage", 10);
}

void close_passage()
{
        object room;

        message("vision","门又关上了.\n", this_object() );
        if( room = find_object(__DIR__"in_cave") ) {
                room->delete("exits/north");
                message("vision","门被从里面关上了.\n", room );
        }
        delete("exits/south");
}
