
// /d/xizang/class/gold_wh/hole1.c

inherit ROOM;

void create()
{
        set("short", "洞内");
        set("long", @LONG
这里是山洞内部,一片黑暗中你看不到什么东西,只好摸索(touch)着前进.不远处
好象传来一声深深的叹息,你侧耳倾听,但只听到你自己紧张的心跳声.
LONG
        );
        set("exits", ([
                 "east" : __DIR__"hole",
]));
        setup();
}

void init()
{
        add_action("do_touch", "touch");
}


void check_trigger(object me)
{
        object room;
        if( (int)query("touch_trigger")>=30
        &&      !query("exits/north") ) {
        message_vision("$N在一片黑暗中摸到一块突起的石头,无意中推了一下.\n"+
        "竟然推开了一片山岩,原来那是个暗门!\n", me);
                set("exits/north", __DIR__"hole2");
                if( room = find_object(__DIR__"hole2") ) {
                        room->set("exits/south", __FILE__);
                        message("vision", "有人从外面把暗门打开了\n", room);
                }
                delete("touch_trigger");
                call_out("close_passage", 10);
        }
}

int do_touch(string arg)
{
        object me;
        if (arg && arg!="") return notify_fail("你摸来摸去,摸不到"+arg+".\n");
        add("touch_trigger", 1);
        me=this_player();
        message_vision("$N在一片黑暗中到处摸索,也不知道要找什么.\n", me);
        check_trigger(me);
        return 1;
}


void close_passage()
{
        object room;
        if( !query("exits/north") ) return;
        message("vision", "暗门在机关作用下自动关上了\n", this_object() );
        if( room = find_object(__DIR__"hole2") ) {
                room->delete("exits/south");
                message("vision","暗门在机关作用下自动关上了\n", room );
        }
        delete("exits/north");
}

