//huay.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"花园"NOR);
        set("long", @LONG
	  花园中香气扑鼻而来，花丛中游廊隐现，皆小巧别致，花草中一条石子
路扫得干干净净，仿佛玉石，直通向远处。
LONG
        );
        set("exits", ([ 
	  	"east" : __DIR__"bhall",
  		"out" : __DIR__"bgate",
	]));
        set("outdoors", "hangzhou");
        setup();
}
/*int valid_leave(object who,string dir)
{   
   	if( userp(who) && random(3))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}*/