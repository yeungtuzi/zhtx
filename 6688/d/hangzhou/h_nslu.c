//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "河坊街");
	set("long", @LONG
	这是一条挺繁华的大街，西边有一家客栈，南边是一处亭台。街上
人来人往，顾客与商人的讨价还价声，游人的笑声，小姑娘的打闹声，混在
一起，十分热闹。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_hfj", 
	"west" : __DIR__"h_kezhan",
	"south" : __DIR__"h_wsxf",
	 ]) );
	set("objects",([
	__DIR__"npc/ren" : 1,
	__DIR__"npc/ren2" : 1,
	__DIR__"npc/h_girl" : 1,
	]));
	
        setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="east")
	{
		//if(random(3)<2)
		//	return notify_fail
		tell_object(ob,"你走在河坊大街上，街上的小贩不停地向你吆喝。\n");
		return 1;
	}
	return 1;
}