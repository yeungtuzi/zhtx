//《天龙八部》
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_cloud();
string *watch_msg=({
HIC"	你的思絮随流云而去，徘徊于青山绿水之间，纵横于草原\n"NOR,
HIC"	戈壁之上，儿时的梦想仿佛成为现实，任狂风刮面，立在\n"NOR,
HIC"	大漠的落日下，荒凉的古堡中，于琵琶反弹声中，凭着楼兰\n"NOR,
HIC"	的残桓，抬头望青天深处长啸一声。风沙席地，飞天漫空，\n"NOR,
HIC"	望着奔腾如烟呼啸如虎的万里长河，你禁不住潸然泪下，合什祈祷。。。。\n\n"NOR,
HIC"你从遐想中回过神来，忽然发现身上多了一本书，不知从何而来。\n"NOR,
});

void create()
{
        set("short", "玉皇山巅");
	set("long", @LONG
	不远处有一座巍峨的寺庙，里面香火旺盛，庙里庙外都由香烟缭绕，
脚下，身边又有流云飞动，如果现在是白天，在金色的阳光下，当有霞光四
射，彩云飞扬。这一景名为“玉皇飞云”，名不虚传。
LONG
        );
        set("exits", ([
	"southdown" : __DIR__"h_yhshan",
	 ]) );
	set("item_desc",([
	"玉皇飞云" : (: look_cloud :),
	"cloud" : (: look_cloud :),
	]));
	set("objects",([
	__DIR__"npc/xiang-ke" : 2,
	]));
       	
	set("count",2);
	setup();
}

string look_cloud()
{
	object ob=this_player();

	if(query("count")<1 || ob->query_temp("watched_cloud")
	 || ob->query_skill("literate",1)>=100)
		return "你沉浸在无限的遐想中。\n";
	ob->start_busy(10);
	ob->set_temp("watched_cloud",1);
	remove_call_out("watch_cloud");
	call_out("watch_cloud",1,ob,0);
	return "你沉浸在无限的遐想中。。。。。。\n";		
}

void watch_cloud(object ob,int stage)
{
	object obj;
	int lit;

	lit=ob->query_skill("literate");

	tell_object(ob,watch_msg[stage]);
	if(++stage<sizeof(watch_msg) )
	{
		call_out("watch_cloud",2,ob,stage);
		return;
	}
	add("count",-1);
	obj=new("/d/hangzhou/npc/obj/book10");
	obj->move(ob);
}

int valid_leave(object ob,string dir)
{
	if(random(4)<2)
			return notify_fail("你往山下走着，脑中还在想着刚才看到的景色。\n");
		return 1;
}

