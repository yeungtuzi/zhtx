// /d/xizang/class/gold_wh/weapon.c

inherit ROOM;

void check_trigger(object me);

void create()
{
        set("short", "兵器库");
        set("long", @LONG
这里是存放一般兵器的房间.各种兵器整齐的排列在架子(shelf)上,擦得闪闪
发光,显然经常有人使用.
LONG
        );
	set("item_desc", ([
	 "shelf" : "这是一个木制兵器架,上面放着几件兵器(weapon)\n",
	"weapon" : "这是件普通的兵器,你可以拿去(take)试试看是否凑手合用\n",
]));
        set("exits", ([
		"north" : __DIR__"sroad1",
]));
        setup();
}

void init()
{
        add_action("do_take", "take");
}

int do_take(string arg)
{
	object ob, me;
	if (!arg || (arg=="")) return notify_fail("你要拿什么?\n");
	if ((arg!="weapon") && (arg!="兵器") && (arg!="武器"))
		return notify_fail("这里没有" + arg +"可拿\n");
	me = this_player();
	ob = new(__DIR__"obj/weapon");
	ob->move(me);
	add("taken_things", 1);
	check_trigger(me);
	return 1;
}

void check_trigger(object me)
{
	object room;
	if ((int)query("taken_things") >= 11) {
		if (me->query("str") < 25) {
	message_vision("$N用尽全身力气,却根本拿不动这件兵器.\n", me);
	return;
	}
	if (!query("exits/south")) {
	message_vision("$N用尽全身力气,试图拿起这件兵器,结果整个\n"+
	"兵器架被拖动了,露出一个小门!\n",me);
	set("exits/south", __DIR__"weapon1");
	if( room = find_object(__DIR__"weapon1")){
		room->set("exits/north", __FILE__);
		message("vision","有人从外面用力拉开了暗门.\n", room);
		}
	call_out("close_passage", 10);
	}
	delete("taken_things");
	}
}

void close_passage()
{
        object room;

        if( !query("exits/south") ) return;
        message("vision","暗门在机关的作用下自动关上了.\n",
                this_object() );
        if( room = find_object(__DIR__"weapon1") ) {
                room->delete("exits/north");
                message("vision","暗门在机关的作用下自动关上了.\n", room );
        }
        delete("exits/south");
}

void reset()
{
        ::reset();
	delete("taken_things");
}
