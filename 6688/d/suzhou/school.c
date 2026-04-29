// This is a room made by roommaker.
//by tlang

#include <ansi.h>
#include <room.h>
inherit ROOM;

int valid_leave(object me, string dir);

void create()
{
	set("short", "精进楼");
	set("long", @LONG
		穿过一个香草芬芳的园子，你来到了镖局弟子门学功夫的精进楼
，楼共有三层，建造的气势磅礴，大有冲天而去之势，让人油然而生敬畏之情。你
身边有一些弟子正在读书，学习一些基本的功夫。看他们那如痴如狂的样子，你也
不得不佩服，镖局中两位年青的长老正在园子中一边聊天，一边指点弟子一些武学
上的道理。旁边就是借书室。
LONG
	);
	set("objects",([
	__DIR__"npc/fighter4" : 1,
	__DIR__"npc/yanqi" : 1,
	__DIR__"npc/guodl" : 1,
	]));
	set("exits",([
	"south" : __DIR__"zhangf",
	"up" : __DIR__"school2",
	"enter" : __DIR__"school0",
	]));
	create_door("south","青竹门","north",DOOR_CLOSED);

	setup();
}

int valid_leave(object me, string dir)
{
        if (!me->query("biao_ju") && dir=="enter" )
	{
	tell_object(me,"一个声音说道： “你非我镖局中人也敢来此，给我乖乖地滚出去吧！
如果不是我辈中人不滥杀，早把送你见无常了。”\n");
	me->set("kee",0);
	me->set("gin",0);
	me->set("sen",0);
	me->move("/d/suzhou/biaoju");
		return notify_fail("你只觉得腾云驾雾一般，被踢出了镖局。\n");
	}
	return 1;
	return ::valid_leave(me, dir);
}
