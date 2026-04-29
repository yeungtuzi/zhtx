//《书剑恩仇录》
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void watch_picture(object ob,int stage);

string *watch_msg=({
	HIC"你静下心来，开始仔细观察这儿的字画。。。。。。\n"NOR,
	HIC"\n"NOR,
	HIC"良久，你终于回过神来。。。。。。\n"NOR,
	HIC"却意外地发现自己手上拿着一本书，看上去十分古老了。\n"NOR,
});

void create()
{
        set("short", "吴山天风");
	set("long", @LONG
	小亭坐落在吴山之下，布局不拘一格，或有挂画垂梁，或有蟠龙附
柱，更有一些迁客骚人题字画于壁上，或俊逸潇洒，或沉稳练达，或婉约清
秀，或豪放泼辣，各有各的好处，让流连忘返。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_nslu", 
	 ]) );
	set("count",2);
	
        setup();
}

void init()
{
	add_action("do_watch","watch");
}

int do_watch(string arg)
{
	object ob=this_player();

	if(!arg || arg!="字画")
		return notify_fail("你要看什么？\n");
	if(ob->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(query("count")<1 || ob->query_temp("watch/picture")
	|| ob->query_skill("literate",1)>=100  )
		return notify_fail("你仔细打量这儿的字画，可惜没有什么收获。\n");
	if(!ob->query_skill("literate",1) )
		return notify_fail("你是文盲，怎么看得出什么呢？\n");
	ob->set_temp("watch/picture",1);
	ob->start_busy(5);
	remove_call_out("watch_picture");
	call_out("watch_picture",1,ob,0);
		return 1;
}	

void watch_picture(object ob,int stage)
{
	object obj;
	int lit;

	lit=ob->query_skill("literate");

	tell_object(ob,watch_msg[stage]);
	if( ++stage<sizeof(watch_msg) )
	{
		call_out("watch_picture",2,ob,stage);
		return;
	}
	obj=new("/d/hangzhou/npc/obj/book11");
	obj->move(ob);
	add("count",-1);
}