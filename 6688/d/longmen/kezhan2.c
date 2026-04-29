inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"龙门客栈二楼"NOR);
        set("long", @LONG
这里就是龙门客栈的二楼了，整个房间装饰得华丽但不失清雅，高贵但不庸
俗，既有叫不出名的古董珍玩，也有千年难见的奇魄古玉，甚至还有绝迹江湖多
年的上古神器，旷世神兵。据说很多江湖中的秘密交易都在这里进行，平头老百
姓是很难到被请这里来的。一个美艳妇人居中而坐，丰姿卓约，仪态万方，有条
不紊地招待着客人。此情此物此景此人，如果你没见过点世面，真不知道该迈哪
条腿了。
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
        "down" : "/d/longmen/kezhan",
]));

        set("objects", ([
                __DIR__"npc/jin": 1,
        ]));

        setup();
}

