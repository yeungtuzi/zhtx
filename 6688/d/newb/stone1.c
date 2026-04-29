///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit __DIR__"newbie_room";

void create()
{
        set("short", "洞穴");
        set("long", @LONG
这里突然变得明亮起来，你发现头顶上有一个正好能钻过的洞，
光线就是从那儿进来的。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                  "up": __DIR__"stone",
                ]));
        set("objects", ([
                        __DIR__"npc/qiu": 1,
                ]));
        set("outdoors", "newbie");

        setup();
}

int valid_leave(object me, string dir)
{
        object npc;
        if(dir == "up") 
        {
                if( npc = present("qiu qianchi", environment(me)))
                        return notify_fail("裘千尺拦住你的去路，看起来不想让你过去的样子。\n");
                
                message_vision(HIC"$N总算走出了魔鬼般的洞穴迷宫，不由长舒了一口气！\n"NOR,me);
        }
         return ::valid_leave(me, dir);
}

