//by tlang
//97.12
//sanya yuan

#include <ansi.h>
inherit ROOM;
string do_look();

void create()
{
	set("short", MAG"三雅园"NOR);
	set("long", @LONG 
	这儿以醋鱼闻名于世，它坐落在湖边，面临一泓春水，用三尺高
的红漆栏杆围住，栏杆旁有十来张洗得发亮的白木桌子，每张桌子上准备
有鱼饵和钓竿。鱼已经放进湖里，要吃，的自己钓上来。外面(out)湖面上
有一艘画鲂，上面有一绝色美人。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"h_wjl",
	]));
	set("objects", ([
		__DIR__"npc/duan" : 1,
	]));
	set("item_desc", ([
                "out" : (: do_look :),
	]));

	setup();
}

void init()
{
	add_action("do_out", "out");
}

string do_look()
{
	return "外面景色优美，最妙的是那艘画舫，翠绿色的顶，朱红的栏杆，雕化的窗户里，湘妃
竹帘半卷。一个风姿绝代的美人，正做在窗口，调弄着笼中的鹦鹉。\n";
}

int do_out()
{
	object me;
	me=this_player();

	if( !me->query("mark/begin") ) 
		return notify_fail("你想干嘛呀？\n");
	me->delete("mark/begin");
	me->set("mark/goon",1);
	tell_object(me,"你身形一动，飘到画舫。\n");
	me->move("/d/hangzhou/huaf");
		return 1;
}
	

