// /d/xizang/class/gold_wh/book.c

inherit ROOM;

void create()
{
        set("short", "武籍存放处");
        set("long", @LONG
这是一个狭小的房间,北边是出口,其余三面排满了书架(shelf),上面放的都是
密宗金轮派的武功典籍(wuji).
LONG
        );
        set("item_desc", ([
                "shelf" : "这是一排整齐的书架,上面放了很多书册.\n",
                 "wuji" : "这是一本武功典籍,你可以拿走(take)它回去读.\n",
        ]));
        set("exits", ([
                "north" : __DIR__"p_hall",
]));
        setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_take", "take");
}

void check_trigger(object me)
{
        if ((int)query("taken_things") >= 9) {
        message_vision("$N拿起一本书,露出一个秘密杠杆(lever)\n",me);
        delete("taken_things");
        remove_action("do_pull", "pull");
        add_action("do_pull", "pull");
        }
}

int do_take(string arg)
{
        object ob, me;
        string wuji;
        if (!arg || arg =="") return 0;
        if (arg!="wuji") return 0;
        me = this_player();
        if (me->query("family" != "密宗金轮派")) {
                ob = new(__DIR__"npc/guard");
                ob->move(this_object());
                ob->kill_ob(me);
                me->fight_ob(ob);               
        }
        ob = new(__DIR__"obj/wuji");
        ob->move(me);
        add("taken_things", 1);
//        check_trigger(me);
        return 1;
}



int do_pull(string arg)
{
        object room, me;
        if (!arg || arg=="") return notify_fail("你要拉动什么?\n");
        if (arg != "lever") return notify_fail("这里没有"+arg+"可以拉\n");
        if (me->query("str") < 25) {
        message_vision("$N用尽全身力气,却根本拉不动这根杠杆.\n", me);
        return 1;
        }
        if (!query("exits/south")) {
        message_vision("$N用尽全身力气,拉动了这根杠杆,结果\n"+
        "书架整个向一边滑去,露出一个小门!\n",me);
        set("exits/south", __DIR__"book1");
        if( room = find_object(__DIR__"book1")){
                room->set("exits/north", __FILE__);
                message("vision","有人从外面用力拉开了暗门.\n", room);
                }
        call_out("close_passage", 10);
        }
        return 1;
}

void close_passage()
{
        object room;

        if( !query("exits/south") ) return;
        message("vision","暗门在机关的作用下自动关上了.\n",
                this_object() );
        if( room = find_object(__DIR__"book1") ) {
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

