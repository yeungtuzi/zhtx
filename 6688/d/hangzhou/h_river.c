//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "九溪十八涧");
	set("long", @LONG
	这儿溪流纵横，水声叮咚，透过清澈的溪水，甚至可以看见游来游
去的鱼儿。整个溪流大致会在一起，往东边逶迤而去。
LONG
        );
        set("exits", ([
	"westup"  : __DIR__"h_ljcun", 
	"eastdown" : __DIR__"h_river2",
	 ]) );
	
        setup();
}

int valid_leave(object ob,string dir)
{
	if(random(6)<4)
		return notify_fail("你沿着溪流走着，两边的景色没有什么变化。\n");
	return 1;
}