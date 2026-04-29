// Room: /d/xixia/generalgate.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "将军府");
	set("long", @LONG
这里便是征东大将军兼一品堂统领赫连铁树的府第，飞檐挂角，
琉璃砖瓦，气宇不凡，不过一般人是没有机会进将军府的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"southstreet2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiwei4" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
}

void reset()
{
	delete_temp("someone_in");
	::reset();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jumpin", "jumpin");
}

int do_jump(string arg)
{
	return notify_fail("你是不是想偷偷溜进王府(jumpin)？\n");
}

int do_jumpin(string arg)
{
	object me = this_player();

	if (me->query_skill("move") < 60)
		return notify_fail("你轻功太差，会被门卫抓住的！\n");

	if (me->query_temp("tieshu") != 4)
		return notify_fail("没事别去找麻烦！\n");

	if (strsrch(NATURE_D->game_time(), "子时") < 0)
		return notify_fail("还是等半夜三更下手比较好！\n");

	if ((int)query_temp("someone_in") > 0)
		return notify_fail("里面乱哄哄的，看来只好明晚再来！\n");

	set_temp("someone_in", 1);
	tell_object(me, HIY"你轻轻一纵越过墙头，悄没声息进了王府。\n"NOR);
	tell_room(environment(), HIY"你只觉眼前一花，似乎有什么人经过，可是仔细一瞧，却什么也没有。\n"NOR, me);
	me->move(__DIR__"groom1");

	return 1;
}
		

int valid_leave(object me, string dir)
{
	if (!me->query("marks/xixia/heliantieshu")
	 && me->query_temp("tieshu") == 6) {
		me->set("marks/xixia/heliantieshu", 1);
		me->delete_temp("tieshu");
		tell_object(me, CYN"赫连铁树受伤，杏子林围剿丐帮之肯定是不成了，你不禁长嘘了一口气！\n"NOR);
		tell_object(me, HIW"得经验十万，潜能三千，武林声望三点，正气一百万，黄金一百两。\n"NOR);
		me->add("combat_exp", 100000);
		me->add("potential", 3000);
		me->add("wlshw", 3);
		me->add("shen", 1000000);
		new("/obj/money/tenthousand-cash")->move(me);
	}

	return ::valid_leave(me, dir);
}
