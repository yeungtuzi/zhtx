//《连城诀》
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string do_look();

string *npcs=({
	"sworder",
	"blader",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", "桃源岭");
	set("long", @LONG
	你登上桃源岭,就看见迎面两座笔直的山峰直插入云宵,这就是著
名的“双峰插云”。不远处几个少年正迎风长立,高谈阔论.山岭中忽然起
雾了,一切都有些朦胧,连面前的两座山峰都分辨不出了.你一洗登山后的
疲劳,有些神采奕奕.如此美景,你不禁动了谈兴,想找个人谈上一番,方不
辜负了如此良景.	
LONG
        );
        set("exits", ([
	"south"  : __DIR__"h_tyl2", 
	 ]) );

	set("item_desc",([
	"mountain" : (: do_look :),
	"双峰插云" : (: do_look :),
	]));
	set("objects",([
	__DIR__"npc/"+npcs[i] : 1,
	]));
	set("trigger",2);	
	setup();
}

string do_look()
{
	object ob=this_player();
	object obj;	

	if(!ob->query_temp("marks/mountain") && query("trigger")>1
	&& ob->query_skill("literate",1)<=100 )
	{
	add("trigger",-1);
	message_vision("$N不禁触景生情,顺口吟出一句诗来......pp\n",ob);
	obj=new("/d/hangzhou/npc/obj/book2.c");
	obj->move(ob);
	ob->set_temp("marks/mountain",1);
		return "萧疏峰畔岭头坐,清冷香中抚萧吟.\n
	突然有人叫道：“好诗！”你抬头就看见一个少年从空中翩然落下，\n
	“你有如此才气，这本《连城诀》就送给你了。”说完他把一本书教\n
	给你，一旋身就不见了。\n";
	}
	tell_object(ob,"你感慨万千,确又不知道怎么表达出来.\n");
	return "只见两座笔直的山峰直插入云宵.\n";
}