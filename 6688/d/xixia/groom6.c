// Room: /d/xixia/groom6.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
前面你看到了一扇纱窗内透出灯光，灯光下隐隐可见一人面窗而
坐，想来就是赫连铁树了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
]));

	setup();
}

void init()
{
        add_action("do_quit", "quit");
	add_action("do_jump", "jump");
}

int do_quit(string arg)
{
        write("一走了之？\n");
        return 1;
}

int do_jump(string arg)
{
	if (arg != "window" && arg != "窗户")
		return notify_fail("当然是跳窗户啦！真笨！\n");
	if (query_temp("someonein"))
		return notify_fail("里面打得砰砰乱响，看来进去也没用！\n");

	message_vision(HIY"$N双脚一蹬，连人带脚扑进窗户，以迅雷不及掩耳之势击向赫连铁树！\n"NOR, this_player());
	this_player()->move(__DIR__"groom7");
	set_temp("someonein", 1);

	return 1;
}

int valid_leave(object me, string dir)
{
        if (present("murong bo") || present("yiping fighter"))
                return notify_fail("想逃？没门！\n");

	if (me->query_temp("tieshu") == 4 && dir == "enter")
		return notify_fail("错啦！应该从窗户里跳进去！\n");

        return ::valid_leave(me, dir);
}

void reset()
{
	delete_temp("someonein");
	::reset();
}
