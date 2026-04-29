//write by lysh
#include "ansi.h"

inherit ROOM;
void create()
{
        set("short", "山谷低");
        set("long", @LONG
    四面悬崖峭壁，周围荒草丛生。这里真是飞鸟、猿猴也无法
到达的绝地。你旁边是一潭碧水，真是一眼望去，深不见底。
LONG
        );
        set("outdoors", "jitang");

        setup();

}

void init()
{
        add_action("do_dive", "dive");
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object 	me;
        int mlvl;
	if(!arg || arg != "up") {
		write("你向哪爬？\n");
		return 1;
	}
	me = this_player();
	mlvl = (int)me->query_skill("dodge");
	if(mlvl < 180) 
		message_vision(HIY "\n$N奋力向上爬去，爬了不到两三丈，只觉的手脚发软，向下滑了下去。\n" NOR, me);
	else {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		me->move(__DIR__"xuanya");
	}
	return 1;
}

int do_dive()
{
        object me=this_player();
        write("你一个猛子扎到了水了。\n");
        me->move(__DIR__"bottom1");
        return 1;

}
