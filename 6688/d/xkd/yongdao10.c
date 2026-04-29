// yongdao2.c
// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
      set("short", HIG"甬道"NOR);
      set("long", @LONG
这是一条长长的甬道，两旁点着油灯，光线虽暗，却也可辨道路，甬道
依着山腹中天然洞穴修凿而成，人工开凿处甚是狭窄，有时却豁然开阔，只
觉渐行渐低，洞中出现了流水之声，琮琮铮铮，清脆悦耳，如击玉罄。
LONG
);
        set("exits", ([
                      "south" : __DIR__"guan",
                      "north" : __DIR__"yongdao5",
                      "east" : __DIR__"yongdao6",
                      "west" : __DIR__"yongdao7",
        ]));

        setup();
        replace_program(ROOM);
} 
 
