//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"复兴街"NOR);
	set("long", @LONG
	这是一条繁华的街道，由于南边不远就是钱塘江，所以临江一边开
有许多楼阁，可以在上面坐着，一边喝着二锅头，一边看着潮起潮落。北边
是一些店铺，都关着门，主人大概到江边凑热闹去了。北边不远是玉皇山。
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_fxj", 
	"east" : __DIR__"h_fxj3",
	"north" : __DIR__"h_yhlu", 
	 ]) );
	
        setup();
}

