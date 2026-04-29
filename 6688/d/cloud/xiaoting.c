
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "花园小亭");
        set("long", @LONG
这是一座座落在张家花园中心的小亭子。在这里可以通向花园深处。亭子
的悬梁上有精美的彩画，看得出有不少工匠在这里花费了心血。亭子中央
有个小石桌，桌子腿上雕刻了麟麒。亭子开着小窗，东风从这里吹进来。
LONG
        );
        set("exits", ([ 
   "west" : __DIR__"bamboo1",
   "south" :__DIR__"rich",
   "east" : __DIR__"bamboo3",
   "north" :__DIR__"bamboo4",
]));
        set("objects", ([
        __DIR__"obj/table" : 1,
        __DIR__"npc/zhanggirl":1,
        __DIR__"npc/shutong":1,
                        ]) );
        setup();
}
void reset()
{
	object *inv;
	object con, item;
	::reset();
	con = present("table", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) && !random(2)) {
	item = new(__DIR__"obj/paper");
	item->move(con);
	}
}
