//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "南山大道");
	set("long", @LONG
	一条紧靠西湖的大道，不远处就是碧蓝的湖水，北边就是夕照山，
山上有著名的雷峰塔，山脚下有一座庙宇，据说是凤林寺，但前门朝着水，
后门终日紧闭，从陆地是没有办法进去了。东边不远处是一家客栈。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_kezhan", 
	"west" : __DIR__"h_nslu4", 
	 ]) );
	
        setup();
}





