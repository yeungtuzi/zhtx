// Room: /d/lingjiu/mi7.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这间石室的四壁岩石打磨的甚是光滑，石壁上刻慢了无数径长尺许的圆圈，
每个圆圈都刻了各种各样的图形，有的是人像，有的是兽行。有的是残缺不
全的文字，更有的只是记号和线条。圆圈旁边注着“甲一”、“甲二”、“
子一”、“子二”等数字。圆圈甚多，至少也有七八百个。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mi6",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_watch", "watch");
	add_action("do_study", "lian");
}

int do_watch(string arg)
{
	int i, j;
	object me;

	me = this_player();
	i = me->query_skill("zhemei-shou", 1);
	j = me->query_skill("liuyang-zhang", 1);
	if( i < 101 && j < 101 )
		return notify_fail("这些图形似乎是讲解一门武功，不过你看不懂！\n");
	if( i == 0 ){
		tell_object(me, "你看出来了有些是天山六阳掌的图解。其余的就看不懂了。\n");
		tell_object(me, "你不禁想照着图中所示练练(lian)。\n");
		return 1;
	}
	if( j = 0 ){
		tell_object(me, "你看出来了有些是天山折梅手的图解。下面的就看不懂了。\n");
		tell_object(me, "你不禁想照着图中所示练练(lian)。\n");
		return 1;
	}
	tell_object(me, "你看出了前面是天山折梅手的图解，接下来是天山六阳掌的图解。\n");
	tell_object(me, "你不禁想照着图中所示练练(lian)。\n");
	
	return 1;
}	

int do_study(string arg)
{
	int i, j, k;
	object me;

	me = this_player();
	i = me->query_skill("zhemei-shou", 1);
	j = me->query_skill("liuyang-zhang", 1);

	if( me->is_busy() )
		return notify_fail("你正忙着了。\n");
	if( i < 101 && j < 101 ){
		message_vision("$N依着墙壁上的图形练了起来！\n", me);
		me->delete_temp("last_damage_from");
		me->receive_wound("kee", 200);
		if( me->query("force") > 500 )
			me->add("force", -500);
		me->start_busy(5);
		tell_object(me, HIR"突然一股内息走入岔道，你手扶石壁，摇摇欲坠。\n"NOR);
		tell_room(environment(me), HIY"你看见"+me->name()+"手扶石壁，黄豆大的汗珠涔涔而下！\n"NOR, me);
		return 1;
	}

	if( !arg || arg =="" )
		return notify_fail("你要练天山折梅手还是天山六阳掌？\n");
	if( me->query("sen") < 50 )
		return notify_fail("还是先歇一歇吧！\n");
	
	k = me->query_skill("force") * 2/3;
	if( arg == "zhemei-shou" ){
                if( i > k )     
			return notify_fail("你内功不够扎实，强行练习上乘武功会走火入魔。\n");
		me->receive_damage("sen", 50);
		me->improve_skill("zhemei-shou", me->query_int());
		tell_object(me, "你就着墙壁上的图形学习天山折梅手。\n");
		tell_object(me, HIY"你的天山折梅手进步了！\n"NOR);
		return 1;
	}

	if( arg == "liuyang-zhang" ){
                if( j > k )     
			return notify_fail("你内功不够扎实，强行练习上乘武功会走火入魔。\n");
		me->receive_damage("sen", 50);
		me->improve_skill("liuyang-zhang", me->query_int());
		tell_object(me, "你就着墙壁上的图形学习天山六阳掌。\n");
		tell_object(me, HIY"你的天山六阳掌进步了！\n"NOR);
		return 1;
	}
	
	return 1;
}
