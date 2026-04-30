//gate.c
//梅庄大门
//by emote
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short","梅庄大门");
    set("long",@LONG

这是一座朱门白墙的大庄院外，行到近处，见大门外写着“梅庄”两个
大字，旁边署着“虞允文题”四字，但觉这几个字儒雅之中透着勃勃英气。
门上有两个擦得精光雪亮的大铜环，你可以上前去敲一下(knock)。
LONG);
     set("exits",([ /* sizeof = 1 */
           "south":"/d/heimuya/qlt1",
           ]));
     setup();
}
void init()
{
       add_action("do_knock", "knock");
}

void wantopen(object me)
{
        // 2026-04-30: unused variable commented out
        // object  waiter, tao1, tao2, tao3;
        object  room;

        seteuid(geteuid());
        room = find_object(__DIR__"hall");
        message("vision", "\n吱的一声，门向里开了。\n", this_object());
        if( room )  message("vision", "吱的一声门自动打开，走了出去。\n", room);
        call_out("closedoor", 10, me);
}


int do_knock(string arg)
{
        object room, me, thisroom;

        if( arg=="door" || arg == "门") {
                me = this_player();
                if(query("exits/north")) {
                        message_vision(HIB "门是开着的，敲什么？\n" NOR, me);
                        return 1;
                }
                message_vision(HIB "$N走到门前，轻轻地用门环敲了两下。\n" NOR, me);
                set("exits/north", __DIR__"hall");
                if( room = find_object(__DIR__"hall") ) {
                        message("vision", HIB "你听到当当两声，有人在门外敲门。\n" NOR, room);
                        room->set("exits/south", __FILE__);
                        room->set("item_desc", ([
                                "door": "铜钉的大门，门是开着的。\n",
                                "门": "铜钉的大门，门是开着的。\n",
                              ]) );
                }
                me->start_busy(2);
                call_out("wantopen", 2, me);
                
        }
        else {
                write("你要敲什么？\n");
        }
                return 1;
}

void closedoor(object me)
{
        object obj, room, troom;
      
        troom = this_object();
        if(environment(me) != troom) {
                room = find_object(__DIR__"hall");
                message("vision","门自动关上了。\n", troom);
                delete("exits/north");
                        if(room) {
                                room->delete("exits/south");
                                room->set("item_desc", ([
                        "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                        "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                                ]) );
                        }
                }
        }
        else
                call_out("closedoor", 15, me);
}
