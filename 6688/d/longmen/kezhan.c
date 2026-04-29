inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"龙门客栈"NOR);
        set("long", @LONG
这家客栈是龙门镖局的本钱开设，因此叫“龙门客栈”，是如今西北数一数
二的大客栈。店小二正面带微笑迎接顾客。柜台右首一溜白漆水牌儿，写着菜名
价码，台子上几个陈旧的酒坛子，散发出浓郁的芳香。店主人是个美貌少妇，一
向只在二楼招呼客人，客栈二楼是雅座酒楼，只供有钱人享乐。后面有几间客房，
可供过往的客人歇脚。
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
        "south" : "/d/road/rjygtodh0",
        "up" : "/d/longmen/kezhan2",
]));

        set("objects", ([
                __DIR__"npc/waiter": 1,
        ]));

        setup();
}


int valid_leave(object me, string dir)
{
       if(dir == "up"){
       if( present("waiter", environment(me)) && (me->query("wlshw") < 100 || me->query("combat_exp") < 12800000 ) )
            return notify_fail(HIR"店小二用鄙夷的目光扫了你一眼，不屑地朝门外努努嘴，意思是让你快点滚出去。\n"NOR);
       message_vision(HIY"\n店小二一见$N，陪着笑脸迎了上来，唱喏道，“这位客官楼上请喽～～”\n"NOR,me);

        }
 //      message_vision(HIY"\n店小二一见$N，陪着笑脸迎了上来，唱喏道，“这位客官楼上请喽～～”\n"NOR,me);
       return :: valid_leave(me, dir);
}

