// /d/xizang/in_cave.c

inherit ROOM;

void create()
{
        set("short", "雪梅洞");
        set("long", @LONG
你发现洞内居然是一个很舒服的房间,北边有一扇木门,钉着精致的铜门环.
LONG
        );
        set("exits", ([
        "out" : __DIR__"shandong",
]));

        setup();
}

void init()
{
	add_action("do_knock", "knock");
}

int do_knock(string arg)
{
	object room;
	if(!arg || (arg!="门" && arg!="door")) 
		return notify_fail("你敲什么敲啊,烦不烦哪!\n");
//        if(!this_player()->query("marks/xiaomei"))
//                return notify_fail("你敲了半天门,但是没有听到任何回音.\n");
	message_vision("$N轻叩铜环,听到小梅在里面轻轻地应了一声:谁呀?", 
		this_player());
this_player()->set("marks/xiaomei",1);
	if(!query("exits/north")) {
	message("vision", "门从里面慢慢地打开了.\n", this_object() );
	set("exits/north", __DIR__"mei_room");
	if( room = find_object(__DIR__"mei_room")){
        	room->set("exits/south", __FILE__);
                message("vision", "小梅打开了门\n", room );
                }
	call_out("close_passage", 10);
	}
	else write("门已经是开着的了.\n");
	return 1;
}

void close_passage()
{
	object room;
        if( !query("exits/north") ) return;
        message("vision", "门被从里面关上了.\n", this_object() );
        if( room = find_object(__DIR__"mei_room") ) {
                room->delete("exits/south");
                message("vision", "小梅把门关上了.\n", room );
        }
        delete("exits/north");
}
