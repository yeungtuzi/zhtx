//by mic

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"忏悔洞"NOR);
	set("long", @LONG
	一进山洞，你不由为石洞的宽敞而大吃一惊。石洞足以容纳数十人。
你若不细看，绝不会认为是人工所凿成的。那巧手匠心的工艺，丝毫没有留下
任何斧凿的痕迹，不由为之赞叹！石洞里已有数人跪在一旁，闭目凝神，丝毫
也不理会别人。原来这里是镖局里有名的忏悔(chanhui)洞！是为护镖失败的人
悔过用的。
LONG
);
	set("exits", ([
		"out": __DIR__"bjhyuan",
	]) );
	setup();
}

//added by tlang for chanhui.
void init()
{
	add_action("do_chanhui","chanhui");
}

int do_chanhui()
{
	object me=this_player();
	
	if(me->query("mark/开始") || me->query("test1") || me->query("test2")
|| me->query("test3") || me->query("test4") || me->query("sender") 
|| me->query("saver") || me->query("marks/killer"))
	{
	tell_object(me,"你诚心悔过，渐渐地从懊悔中解脱出来。\n");
	me->start_busy(10);
	me->delete("mark/开始");
	me->delete("test1");
	me->delete("test2");
	me->delete("test3");
	me->delete("test4");
	me->delete("sender");
	me->delete("saver");
	me->delete("marks/killer");
		return 1;
	} else {
		return notify_fail("你又没有什么过错，忏悔什么啊？哼！\n");
	}
}
	