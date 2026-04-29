// /d/xizang/class/gold_wh/weapon1.c

inherit ROOM;

void create()
{
        set("short", "兵器库密室");
        set("long", @LONG
这里是存放高级弟子所用兵器的房间.这里的兵器多半较贵,也更加沉重,一般人
根本拿也拿不动.
LONG
        );
        set("exits", ([
		"north" : __DIR__"weapon",
]));
	set("objects", ([
		__DIR__"obj/falun" : random(3),
		__DIR__"obj/chu" : random(3),
		__DIR__"obj/bang" : random(3),
		__DIR__"obj/quan" : random(3),
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
	if ((arg!="door") && (arg!="门") && (arg!="north") && (arg!="暗门"))
		return notify_fail("这里没有" + arg +"可打开\n");
	me = this_player();
        if( query("exits/north") ) return notify_fail("门开着呢!\n");
	set("exits/north", __DIR__"weapon");
        if( room = find_object(__DIR__"weapon")){
                room->set("exits/south", __FILE__);
                message("vision","有人从里面用力拉开了暗门.\n", room);
		room->delete("taken_things");
	}
	return 1;
	call_out("close_passage", 10);
}

void close_passage()
{
        object room;

        message("vision","暗门在机关的作用下自动关上了.\n",
                this_object() );
        if( room = find_object(__DIR__"weapon") ) {
                room->delete("exits/south");
                message("vision","暗门在机关的作用下自动关上了.\n", room );
        }
        delete("exits/north");
}
