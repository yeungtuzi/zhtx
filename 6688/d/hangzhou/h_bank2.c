//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"苏堤"NOR);
	set("long", @LONG
	游西湖，最好是携至亲至爱的人骑马满步苏堤，看柳絮飞，看鱼波
兴，看浅草没马蹄，说杭州的美，说西湖的美，说自己身边人儿的美。让你
看的眼睛都迷离了，说得心都化成蜂蜜了。
LONG
        );
        set("exits", ([
	"north" : __DIR__"h_bank",
	"south" : __DIR__"h_cross2",
	 ]) );

	 setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}*/

