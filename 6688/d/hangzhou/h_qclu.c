//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "庆春大街");
	set("long", @LONG
	庆春街是杭州的商业地区与风景地区的界限，往东是杭州的商业繁
华区，往西就是以西湖为中心的风景区。北边不远处有座小亭，往南可以通
向是河坊街口，再往南就是复兴街了。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_qclu2", 
	"south" : __DIR__"h_hfj", 
	 ]) );
	
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}
*/
