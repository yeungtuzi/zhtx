//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山道");
	set("long", @LONG
	此处显得较宁静，路也显得有些崎岖，路上几乎没有行人，可以
通向著名的险地一线天。南边有一家酒楼。
LONG
        );
        set("exits", ([
	"westup"  : __DIR__"h_yxt", 
	"northdown"  : __DIR__"h_lylu",
	"south" : __DIR__"h_twt",
	 ]) );
	
	setup();
}


	

