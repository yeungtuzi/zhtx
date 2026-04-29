// gate.c 乾坤教总舵正门
// by Masterall
 
#include <ansi.h>
 
inherit ROOM;
 
void create()
{
        set("short", "乾坤教总舵正门");
        set("long","这里是乾坤教总舵的正门，是乾坤教接收教众的地方。大门上高挂着一块金匾：
 
                         " + HIR "乾     坤     教" NOR + "
 
 东西两侧是走廊，南边是练武的广场，北边是后院。\n");
        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"guangchang",
                "north" : __DIR__"qianting",
                "east" : __DIR__"donglang",
                "west" : __DIR__"xilang", 
        ]));
        set("objects", ([
                __DIR__"npc/jiaozhong" : 3, 
                __DIR__"npc/shangguan" : 1, 
]));
        set("objects",([
                 __DIR__"npc/jiaotu" : 4,
                 __DIR__"npc/zhaowuji" : 1,

         ]));
        setup();
 //     replace_program(ROOM);
  //      "/obj/board/wudang_b"->foo();
}

 
