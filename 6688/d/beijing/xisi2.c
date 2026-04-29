inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", CYN"西四北大街"NOR);
	set("long", @LONG
这里是西四北大街。南边通往京城最繁华的地方－－西单。东边
通向北海和神武门,这里来往的人比南边少多了，多是一些行色匆匆
的过往商贾。在这年头，谁不是为了一个钱字东奔西跑啊！
LONG
	);
        set("outdoors", "bj");

	set("exits", ([
		"south" : __DIR__"xisi",
		"east" : __DIR__"beihai1",
                "north" : __DIR__"yamen",
	]));
	setup();
	replace_program(ROOM);
}


