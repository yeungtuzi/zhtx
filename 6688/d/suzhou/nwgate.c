// nwgate.c
//by tlang 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", YEL"宁王府"NOR);
    set("long", @LONG
一个巨大的牌坊横架在两片山壁之间，牌坊正上方刻着三个斗大的字:宁王
府。字迹有些剥落，看上去年代久远。两位三十来岁的红衣侍卫手持戒刀守
在大门两侧。两侧立着石狮子。
LONG
    );
    set("exits", ([
        "northup" : __DIR__"nwqy",
        "out" : __DIR__"bjhyuan",
    ]));

    set("outdoors", "suzhou");
    set("objects",([
        CLASS_D("guard") + "/npc/redshw" : 2,
       
    ]));
    setup();
}












