// shanlu1.c 山路
// by Masterall
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"石室"NOR);
        set("long", @LONG
这是一件甚为宽敞的石室，只见两边是块打磨光滑的大石壁，石壁旁点燃着八根 
大火把，照耀明亮。壁上刻得有图有字。石室中已有十多人，有的注目凝思，有的打
坐练功，有的闭着双目喃喃自语，更有三四人在大声争辩。 
LONG
        );
 
        set("exits", ([
                "north" : __DIR__"s17",
                "south" : __DIR__"s18",
                "west" : __DIR__"sc1",
        ]));
        setup();

} 
 


