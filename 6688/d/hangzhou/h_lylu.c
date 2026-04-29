//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山道");
	set("long", @LONG
	此处显得较宁静，路也显得有些崎岖，路上几乎没有行人，可以
通向著名的险地一线天。
LONG
        );
        set("exits", ([
	"southup"  : __DIR__"h_lylu2", 
	"northeast"  : __DIR__"h_tyl",
	 ]) );
	
	setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有明显变化。\n");
	return 1;
}*/
	

