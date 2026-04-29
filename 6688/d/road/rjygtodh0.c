#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short",HIC "驿道" NOR);
	set("long", @LONG
一条驿道静静的向远方延伸，好象永远没有尽头。
北面就是远近闻名的龙门客栈了，很多远行的客商、武林中人都在那里打尖歇脚。
LONG
	);
	set("exits", ([ 
  "east"  : __DIR__"jiayuguan",
  "west" : __DIR__"rjygtodh1",
  "north" : "/d/longmen/kezhan",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

int is_road() {
	return(1);
}

