#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "华山别院--庭院");
        set("long", @LONG
这里就是华山别院大院所在。华山剑气二宗相争后，剑宗一败涂
地，让出掌门之位后在此苦练。这里的大院里面种着许多的槐树，有
一株特别高大，看起来挺神秘的样子，不知道有什么秘密在里面。华
山剑宗的一位弟子正在这里指导其他弟子们一些入门的功夫。左边的
一间大屋是剑宗长老成不忧的居所，右边的就是当今剑宗掌门封不平
的居所了。
LONG
        );

        set("no_sleep_room",1);
        set("outdoors", "huashan");

        set("item_desc", ([
                "hole" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
        ]));

        set("exits", ([
                "east" : __DIR__"fengroom",
                "south" : __DIR__"bieyuan",
                "west" : __DIR__"chengroom",
                "north" : __DIR__"zhengting",
        ]));
        set("objects", ([
                __DIR__"npc/dizi1" : 1,
                __DIR__"npc/dizi" : 4,
        ]));

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="shudong" ) 
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}       
