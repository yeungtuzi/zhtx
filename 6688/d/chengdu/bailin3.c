
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "甬道");
	set("long", @LONG
	这是一条笔直的大道，道路向南北延伸。道路两侧种满了苍松翠柏，
北面是武候祠。
LONG
	);


	set("exits", ([
		"north" : __DIR__"wuhouci",
		"south" : __DIR__"bailin2",
	]));

        set("objects", ([
                "/d/qingcheng/npc/dizi2" : 1,
        ]));

	set("outdoors", "city");
	setup();
}

