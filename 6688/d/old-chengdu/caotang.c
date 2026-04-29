
#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", HIG"杜甫草堂"NOR);
	set("long", @LONG
	这是一间简陋的草房，但是依山傍水，地势绝佳。房中布置简洁，最为
引人注目的就是西边墙侧那一排排的书架(Shelf)了。房间的主人显然腹有诗书
气自华，自有一番大家气象.
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"north" : __DIR__"dongjiao2",
	]));

	set("objects", ([
	]));

	setup();
}
