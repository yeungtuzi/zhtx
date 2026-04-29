//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "庆春大街");
	set("long", @LONG
	庆春街是杭州的商业地区与风景地区的界限，往东是杭州的商业繁
华区，往西就是以西湖为中心的风景区。北边有座小亭，再往北就是杭州中
心的武林广场，往南可以通向复兴街。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"chting", 
	"south" : __DIR__"h_qclu", 
	"west" : __DIR__"h_nslu2",
	 ]) );
	
        setup();
}



