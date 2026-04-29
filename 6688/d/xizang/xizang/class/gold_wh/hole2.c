// /d/xizang/class/gold_wh/hole2.c

inherit ROOM;

void create()
{
        set("short", "密室");
        set("long", @LONG
这里是一间狭小肮脏的密室,用来囚禁雪人.
LONG
        );
        set("exits", ([
		 "south" : __DIR__"hole1",
]));
	set("objects", ([
		__DIR__"npc/snowman" : 1,
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
        if ((arg!="door") && (arg!="门") && (arg!="south") && (arg!="暗门"))
                return notify_fail("这里没有" + arg +"可打开\n");
        me = this_player();
        if( query("exits/south") ) return notify_fail("门开着呢!\n");
        set("exits/south", __DIR__"hole1");
        if( room = find_object(__DIR__"hole1")){
                room->set("exits/north", __FILE__);
                message("vision","有人从里面用力拉开了暗门.\n", room);
                room->delete("touch_trigger");
        }
        return 1;
        call_out("close_passage", 10);
}

void close_passage()
{
        object room;
        if( !query("exits/south") ) return;
        message("vision", "暗门在机关作用下自动关上了\n", this_object() );
        if( room = find_object(__DIR__"hole2") ) {
                room->delete("exits/north");
                message("vision","暗门在机关作用下自动关上了\n", room );
        }
        delete("exits/south");
}
