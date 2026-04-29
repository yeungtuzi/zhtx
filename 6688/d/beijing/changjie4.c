#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"十里长街"NOR);
	set("long", @LONG
这是一条青石大街，大街贯穿东西，向两边延伸。东边是一座富丽堂皇
的大楼，门额上悬挂一方横匾，写着“康亲王府”四个大字，乃是康熙皇帝
亲笔。西边是通往广场的长街。
LONG
	);
        set("outdoors", "bj");

	set("exits", ([
		"west" : __DIR__"changjie3",
		"east" : __DIR__"kang1",
	]));

	setup();
	replace_program(ROOM);
}

