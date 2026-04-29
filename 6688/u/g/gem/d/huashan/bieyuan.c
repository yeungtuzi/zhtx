//华山别院
//bieyuan.c
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "华山别院大门");
        set("long", @LONG
这里就是华山别院所在。华山剑气二宗想争后，剑宗一败涂地，让出
掌门之位后在此苦练。门口正有两个剽悍的小伙子在这里看守着华山剑宗
的门户。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"southwestdown" : __DIR__"laojungou",
		"north" : __DIR__"zhongting",
	]));
        set("objects", ([
               __DIR__"npc/guard": 2,
        ]));
        setup();
        replace_program(ROOM);
}
