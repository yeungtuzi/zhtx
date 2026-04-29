//write by lysh
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山间小路");
        set("long", @LONG
这是一条笔直的，由晶莹的白石铺成的道路。路旁是两行修剪整齐的
花草，微风吹过，花香袭人。白色的晶石在天光下闪著迷人的色彩。一切
显的是那样的宁静，可你的内心却有一种不祥的预感。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bridge",
  "northup":__DIR__"xuanya",
 ]));
        
        set("outdoors", "jitang");
        setup();
}
int valid_leave(object me, string dir)
{
	message_vision( HIC "一阵淡淡的花香飘过，$N不由地深吸了一口气。\n\n\n" NOR,me);
	if(!me->query_condition("zhang_qi"))
		me->apply_condition("zhang_qi",random(10)+10);

	return 1;
}
