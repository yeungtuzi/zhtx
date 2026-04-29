// Room: /d/qiankun/cangjing2.c
//by masterall
//2003.6.30 

inherit ROOM;

void create()
{
        set("short", "藏经阁一楼");
        set("long", @LONG
这是乾坤教藏经阁的一楼，已经长久不用，四处布满了灰尘和蜘蛛网。随地
丢着乱七八糟的书籍，看来也不像是什么武林秘笈了，都是些小儿科的东西了。
仔细一看好像还有个书架(shelf)，上面隐约有人触碰过的痕迹。
LONG
        );
        set("exits", ([
                "up" : __DIR__"cangjingge",
        ]));

        set("item_desc", ([
                "shelf": "这个架子上堆满了厚厚灰尘，除此之外空无一物。\n"
        ]) );

        setup();
}

void init()
{
        add_action("do_push", "push");
}

void check_trigger()
{
        object room;

        if( (int)query("left_trigger")==4
        &&      (int)query("right_trigger")==6
        &&      !query("exits/down") ) {
                message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，露出一个向下的阶梯。\n",
                        this_object() );
                set("exits/down", __DIR__"mishi1");
                if( room = find_object(__DIR__"mishi1") ) {
                        room->set("exits/up", __FILE__);
                        message("vision", "天花板忽然发出轧轧的声音，露出一个向上的阶梯。\n",
                                room );
                }
                delete("left_trigger");
                delete("right_trigger");
                call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision", "地板忽然发出轧轧的声音，一块地面缓缓移动著，将向下的通道盖\住了。\n",
                this_object() );
        if( room = find_object(__DIR__"mishi1") ) {
                room->delete("exits/up");
                message("vision", "天花板忽然发出轧轧的声音，向上的阶梯又缓缓地收了回去。\n",
                        room );
        }
        delete("exits/down");
}


int do_push(string arg)
{
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="shelf" ) {
                write("你试著推动这个架子，似乎可以左右滑动....\n");
                return 1;
        }
        if( sscanf(arg, "shelf %s", dir)==1 ) {
                if( dir=="right" ) {
                        message_vision("$N将架子往右推...，忽然「喀」一声架子又移回原位。\n", this_player());
                        add("right_trigger", 1);
                        check_trigger();
                        return 1;
                } else if( dir=="left" ) {
                        message_vision("$N将架子往左推...，忽然「喀」一声架子又移回原位。\n", this_player());
                        add("left_trigger", 1);
                        check_trigger();
                        return 1;
                } else {
                        write("你要将架子推向那个方向？\n");
                        return 1;
                }
        }
}


void reset()
{
        ::reset();
        delete("left_trigger");
        delete("right_trigger");
}
