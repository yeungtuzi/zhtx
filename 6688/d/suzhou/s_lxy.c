// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"丽夏院"NOR);
	set("long", @LONG
	     这是苏州城中最最风流的地方，本地的，外地的有钱人，不管年
老的，还是年少的，都带着满袋子钱来这儿寻快活。据说这院子是韦小宝因为
不满年轻时他妈工作处老鸨的凶恶，自己立志开的。
LONG
);
	set("exits",([
	"north" : __DIR__"s_yhx",
	"up" : __DIR__"s_lxy2",
	]));
	set("objects",([
	__DIR__"npc/s_lbao" : 1,
	]));

	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="up")
	{
		if(!ob->query_temp("up/allowed") )
			return notify_fail("你没有被允许上去。\n");
	//	tell_object(environment(ob),"这小子兴高采烈地跑了上去。\n");
		ob->delete_temp("up/allowed");
		message_vision("$N兴高采烈地跑了上去。\n",ob);
		return 1;
	}
	return 1;
}