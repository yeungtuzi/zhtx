// /d/xizang/class/dazhao/tower.c

#include <obj.h>

inherit ROOM;

void create()
{
        set("short", "塔林");
        set("long", @LONG
这是大招寺后院的塔林,本寺历代高僧埋骨于此.其中最高的那座中空约
十丈高的尖塔内葬的就是祖师葛伦.尖塔的内部终日不见阳光,长满了又滑又
腻的绿苔.塔虽然破旧,却有很多虔诚的信徒到这里膜拜.
LONG
        );
        set("exits", ([
//                "south" : __DIR__"templeyard2",
                "east" : __DIR__"backyard",
//                "west" : __DIR__"chanhouse",
//                "north" : __DIR__"templeyard3",
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("objects", ([
                __DIR__"npc/keeper" : 1,
        ]));
        setup();
}

// 增加磕头长佛法等等

void init()
{
	add_action("do_ketou", "ketou");
	this_player()->set_temp("ketou_times", 50);
}

int do_ketou(string arg)
{
	object me;
	int skill;
	if (arg && arg!="") return 0;
	me = this_player();
	if ( me->query_temp("ketou_times") == 0 )
	{
                message_vision("$N磕头磕得晕了过去。\n", me);
                me->set_temp("ketou_times", random(50));
                me->unconcious();
                return 1;
        }
	if( me->query("kee") < 50 )
		return notify_fail("你太累了，歇歇吧。\n");

	me->add_temp("ketou_times", -1);
	message_vision("$N虔诚地跪下来,在历代祖师的灵骨塔前磕头。\n", me);
	me->add("kee",-30);
	skill=(int)me->query_skill("zang-buddhi", 1);
	if(skill<=100)
		me->improve_skill("zang-buddhi", random(me->query("int")));
	if(skill>209 && me->query_kar()>25 && random(30)>28) {
		message_vision("$N听到天空中似乎有个声音在召唤自己.\n", me);
		me->move(__DIR__"heaven");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
        if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");
        return ::valid_leave();
}
