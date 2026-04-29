// Room: /u/p/pock/bj/nanku.c
#include <ansi.h>
inherit ROOM;
string* objs = ({
        "ruantie",
        "sichou",
        "tongxian",
});


void create()
{	int i = random(sizeof(objs));

	set("short", HIM"南库"NOR);
	set("long", @LONG
这里是宫中用于存放各种布匹 材料 钢铁等物品的。一般人是进不来的，只有你
手中有各监批条才能在这里领到你所需要的东西。宫中的管理甚严，如果这里有什么
闪失的话，当班的可要吃不了兜着走了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"guodao",
		]));
	set("no_fight",1);
	set("no_magic",1);
	set("objects",([
		__DIR__"npc/dangzhi":2,
		__DIR__"obj/"+objs[i] :1,
		]));
	setup();

}
int valid_leave(object me,string dir)
{
        if (me->query("marks/got") && 
dir=="east" && (present("dangzhi taijian", environment(me))))
        return notify_fail("当值太监说道：“你没有拿来批条就想领东西走？ 没门。”\n");
        return ::valid_leave(me, dir);
}
void init()
{     add_action("do_get","get");
}
int do_get(string arg)
{
	object me;
	me = this_player();
       if (arg=="ruantia" ||arg=="tongxian"||arg=="sichou"||arg=="all")
	  me->add("marks/got",1);
}
	
