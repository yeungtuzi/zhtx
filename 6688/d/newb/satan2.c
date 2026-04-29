///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void check_trigger_fast();
void on_board_fast();
void arrive_fast();
void close_passage_fast();
int do_yell(string);
void reset();


void create()
{
    set("short", "沙滩");
    set("long", @LONG
这儿是海边的一片沙滩。不知为什么，从这儿到附近的小岛有
快船来回摆渡。近岸处有一叶小舟，也许喊(yell)一声船家就能听见。
LONG
    );

    set("exits", ([
                   "north" :  __DIR__"rocks",
    ]));

    set("outdoors", "newbie");
    setup();
}


void init()
{
    add_action("do_yell", "yell");
}

void check_trigger_fast()
{
    object room;

    if(!query("exits/duchuan") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger_fast")==0 ) {
                room->set("yell_trigger_fast", 1);
                set("exits/fastboat", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board_fast");
                call_out("on_board_fast", 10);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}

void on_board_fast()
{
    object room;

    if( !query("exits/fastboat") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
                                                           }
    delete("exits/fastboat");

    remove_call_out("arrive_fast");
    call_out("arrive_fast", 10);
}

void arrive_fast()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", __DIR__"satan1.c");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage_fast");
    call_out("close_passage_fast", 10);
}

void close_passage_fast()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger_fast");
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="fastboat" ) arg = "船老大";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg == "船老大" )
     {
         check_trigger_fast();
         return 1;
     }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger_fast");
}

