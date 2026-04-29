//yuquandoor.c玉泉院大门
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","玉泉院大门");
	set("long",
@LONG
这是玉泉院的黑漆大门，这两扇大门平时的都是关上的，只有逢节日的
时候才会敞开。你可以试着去敲一下大门，看看有没有人会给你开开。门上
方有一块巨大的黑底金漆的匾，上面龙飞凤舞的写着三个大字：“玉泉院”。
LONG);
	set("outdoors","huashan");
        set("item_desc", ([
                "door": "黑漆的大门，门上有门环，你可以敲(knock)。\n",
                "门": "黑漆的大门，门上有门环，你可以敲(knock)。\n",
        ]));
         set("exits", ([ /* sizeof() == 2 */
		"south"  : "/d/village/eexit",
	]));
	set("outdoors","huashan");	
	setup();
}
void init()
{
        add_action("do_knock", "knock");
}

void wantopen(object me)
{
        object  waiter, tao1, tao2, tao3;
        object  room;

        seteuid(geteuid());
        room = find_object(__DIR__"dayuan");
        waiter = new(__DIR__"npc/xiao-daoshi.c");
        message("vision", "\n吱的一声，门向里开了。\n", this_object());
        message("vision", waiter->name()+ "走了过来。\n", this_object());
        if( room )  message("vision", waiter->name() + "吱的一声把门打开，走了出去。\n", room);
        waiter->move(this_object());
        message("vision", "一位小道士说道：这位"+ RANK_D->query_respect(me) + 
                "请进。\n", this_object());
        call_out("closedoor", 10, me);
}

int do_knock(string arg)
{
        object room, me, thisroom;

        if( arg=="door" || arg == "门")
         {
                me = this_player();
                if(query("exits/east")) 
                {
                        message_vision(HIB "门是开着的，敲什么？\n" NOR, me);
                        return 1;
                }
                message_vision(HIB "$N走到门前，轻轻地用门环敲了两下。\n" NOR, me);
                set("exits/east", __DIR__"dayuan");
                if( room = find_object(__DIR__"dayuan") ) 
                {
                        message("vision", HIB "你听到当当两声，有人在门外敲门。\n" NOR, room);
                        room->set("exits/west", __FILE__);
                        room->set("item_desc", ([
                                "door": "黑漆的大门，门是开着的。\n",
                                "门": "黑漆的大门，门是开着的。\n",
                	 ]));
                }
                me->start_busy(2);
                call_out("wantopen", 2, me);
                
        }
        else
           write("你要敲什么？\n");
           return 1;
}

void closedoor(object me)
{
        object obj, room, troom;

        troom = this_object();
        if(environment(me) != troom) 
        {
                room = find_object(__DIR__"dayuan");
                obj = present("xiao daoshi", troom);
                if(obj)
                 {
                        message("vision", obj->name() + "走进道观，轻轻地把门关上了。\n", troom);
                        destruct(obj);
                        delete("exits/east");
                        if(room) 
                        {
                                room->delete("exits/west");
                                room->set("item_desc", ([
                        		"door": "黑漆的大门，门是关着的，你可以拉(pull)门。\n",
                        		"门": "黑漆的大门，门是关着的，你可以拉(pull)门。\n",
                                	]));
                         }
                  }
	
        }
        else
        call_out("closedoor", 15, me);
}
