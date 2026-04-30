inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "白石");
        set("long", @LONG
这是一块巨大的白色山石，大约可以容纳六七个人。石头的表面异常
平滑，石头上面有两个环形的印迹，不知道是天然而成，或是人为的
痕迹。向下望，可以看到碧兰的湖水；向上望，只见上面云雾缭绕，不
知还有多高才会到顶。
LONG
        );
	set("outdoors","mingjiao");
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "push");
}

int do_step(string arg)
{
	object me;

	me = this_player();

	if(!arg || arg != "印迹" )
		return notify_fail("你要推什么？\n");
	if( me->query("max_force") < 500)
		return notify_fail("你用力推了推印迹，结果没有什么动静。\n");
	message_vision(HIY "$N用力推了推印迹，只听到＂吱呀＂一声，\n崖壁上裂开了一道门户！\n" NOR, me);
	set("exits/enter", __DIR__"holeopen2");
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	// 2026-04-30: unused variable commented out
	// int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("你要往上或下爬？\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		message_vision(HIR "\n$N手上一个没抓稳，从危崖上掉了下去！\n" NOR, me);
		me->move(__DIR__"yadi");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
                me->receive_wound("gin", 50);
		message_vision(HIR "\n$N从危崖上掉了下来，重重的摔在了地上！\n" NOR, me);
		me->unconcious();
	}
	else {
		message_vision(HIY "$N小心翼翼地向下爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}
