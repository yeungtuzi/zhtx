//dayuan.c大院
//By Emote
inherit ROOM;

int do_pull(string arg);
void create()
{
	set("short","玉泉院大院");
	set("long",
@LONG
进了大门，你的眼界一下子开阔了起来，面前是一个很宽阔的大院子，
院子四周生着一十二株巨大的龙藤，相传是陈抟老祖亲手所植。至于是不是
真的，那就只有天知道了。院子正对着一眼清泉，那就是玉泉院之所以由希
夷祠改名为玉泉院的原因了。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"yuquan",
		"north" : __DIR__"dadian",
]));
	set("outdoors","huashan");
	setup();
//	replace_program(ROOM);
}


void init()
{
        add_action("do_pull", "pull");
        if(query("exits/west")) 
        set("item_desc", ([
                "door": "铜钉的大门，门是开着的。\n",
                "门": "铜钉的大门，门是开着的。\n",
        ]) );
 
        else 
        set("item_desc", ([
                "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        ]) );
        
}

int do_pull(string arg)
{
        object room, me;

        if( arg=="door" || arg == "门") {
                me = this_player();
                if(query("exits/west")) {
                        write("门是开着的！\n");
                }
                else {
                set("exits/west", __DIR__"yuquandoor");
                set("item_desc", ([
                 "door": "黑漆的大门，门是开着的。\n",
                 "门": "黑漆的大门，门是开着的。\n",
                 ]) );
                message_vision("$N打开大门。\n", me);
                if( room = find_object(__DIR__"yuquandoor") ) {
                        message("vision", "大门从里面打了开来。\n", room);
                        room->set("exits/east", __FILE__);
                        call_out("closedoor", 5, room);
                }
                }
        }
        else {
                 write("你要开什么？\n");

        }
        return 1;
}

int closedoor(object room)
{
        message("vision", "大门又被关上了。\n", room);
        message("vision", "大门又被关上了。\n", this_object());
        set("item_desc", ([
                "door": "黑漆的大门，门是关着的，你可以拉(pull)门。\n",
                "门": "黑漆的大门，门是关着的，你可以拉(pull)门。\n",
        ]) );
        room->delete("exits/east");
        delete("exits/west");
}
