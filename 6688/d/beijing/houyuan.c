#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"小院"NOR);
	set("long", @LONG
这里是一个小院。院落里种了一棵大槐树，槐树长的正茂盛呢。整个院落
非常的幽静，院子西边有一间很别致的房子，可能是一些比较得势的宦官的住
所，院子不大，北边是一条小小的过道，通往后宫。
LONG
	);
        set("outdoors", "bj");
	set("exits", ([
		"east" : __DIR__"zoulang1",
		"north":__DIR__"guodao",
		"west":__DIR__"fang2",
	]));

	setup();
	replace_program(ROOM);
}

