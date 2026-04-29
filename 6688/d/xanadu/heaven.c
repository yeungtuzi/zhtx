// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
        set("short",CYN"极乐世界"NOR);
        set("long", @TEXT
    这里就是天上人间，虚无飘渺的极乐世界，这里你能感受到的只有自己的
意识，没有物质的存在，没有力量的存在，据说只有真正超越了自我，超越了时空
超越了极限的人才可以到达这里，与佛同伴，与上帝同在，也许你就是佛，你就是
上帝，你就是安拉。你可以任意改变一切，但可能你的一切都将改变。天道使然，
无人可以预料，冥冥中自有安排。
TEXT
        );

        set("exits", ([ /* sizeof() == 2 */
//          "down": __DIR__"xukong",
        ]));

        set("objects", ([ 
                        "/d/xanadu/npc/saodiseng" : 1,
                ])
        );
       

        setup();
}  

void init() {

        add_action("do_stay","stay");
}


int do_stay(string arg) {

        object ob,me;
        me=this_player();

        if (!objectp(ob = present("moon casket",me) ) )
        return notify_fail("别指望了，这里飞不出去！\n"); 
        me->start_busy(10);
}

