//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"杨氏大药铺"NOR);
	set("long", @LONG
	这儿暂时不开放。
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_wlgc", 
	 ]) );
	
        setup();
}

