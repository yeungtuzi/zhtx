#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。路西北方向远远可以
看到一个小村落。
LONG
	);
	set("exits", ([ 
  "north"  : __DIR__"rshgtoft1",
  "south" : __DIR__"shanhaiguan",
  "northwest" : "/d/snow/sroad1",
]));

	set("outdoors", "road");
	set("objects", ([
		"/class/shaolin/tuoboseng.c":1,
	]));

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

