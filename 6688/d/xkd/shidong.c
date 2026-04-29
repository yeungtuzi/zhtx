// yongdao2.c
// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
      set("short", HIY"侠客岛正厅"NOR);
      set("long", @LONG
穿过几处石洞后，但听得钟鼓丝竹之声更响，眼前突然大亮，只见一座大山洞 
中点满了牛油蜡烛，洞中摆着一百来张桌子。宾客正络绎进来。这山洞好大，虽摆 
了这许多桌子，仍不见挤迫。数百名黄衣汉子穿梭般来去，引导宾客入座。所有宾 
客都是各人独占一席，亦无主方人士相陪。众宾客坐定后，乐声便即止歇。
LONG
);
        set("exits", ([
                      "north" : __DIR__"houshan",
                      "south" : __DIR__"guan",
        ]));
        set("objects",([
                "/d/xkd/npc/long" : 1,
                "/d/xkd/npc/mu" : 1,
                "/d/xkd/npc/puren2" : random(10)+3,
        ]) );

        setup();
} 
 
