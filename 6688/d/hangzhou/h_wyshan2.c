//《神雕侠侣》
//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;
void come_out(object ob,int stage);
string look_cloud();

string *out_msg=({
	HIC"	你心情轻松下来，寻一方草坪，于清风暖阳中坐下，懒洋洋地\n\n"NOR,
	HIC"	打了一个呵呵欠，伸了两个懒腰，正要舒舒服服地躺下去，有\n\n"NOR,
	HIC"	萧声在耳边响起。萧声自竹林中而来，越过莽莽竹海，直飞到\n\n"NOR,
	HIC"	面前，时而激昂悲壮，恍惚中你看见秦时明月汉时关上那位远\n\n"NOR,
	HIC"	古的剑客正痛饮醇酒，拔剑起舞；时而清丽飘逸，一如天外的\n\n"NOR,
	HIC"	仙子在品罢香茗之后莲步轻移，柳腰轻摆，蝶衣轻飘，在云烟\n\n"NOR,
	HIC"	缭绕中翩然起舞。没有喝酒，你已经醉了。\n\n"NOR,
	HIC"然后你就看见一位白衣似雪，美若少女的少年走了过来。\n\n"NOR,
});

void create()
{
        set("short", HIC"五云山巅"NOR);
	set("long", @LONG
	你现在站在五云上巅。四周是数不尽的竹山竹海，更有一层轻而不
淡的云烟笼罩。风起，竹子婉声歌唱，云烟起舞翩翩。相传一位不知名的少
年诗人在看罢这一翻景色后，禁不住脱口而出：好一个云栖竹径！你已经分
不轻自己是在什么地方了，也许是梦中吧。
LONG
        );
        set("exits", ([
	"eastdown"  : __DIR__"h_wyshan", 
	 ]) );
	set("item_desc",([
	"云栖竹径" : (: look_cloud :),
	"cloud" : (: look_cloud :),
	]));

	set("count",3);	
        setup();
}

string look_cloud()
{
	object ob=this_player();

	if(query("count")<1)
		return GRN"清风中，竹子婉声歌唱，云烟起舞翩翩。\n"NOR;
	add("count",-1);
	if(query("count")!=2)
		return HIR"清风中，竹子婉声歌唱，云烟起舞翩翩。\n"NOR;
	remove_call_out("come_out");
	call_out("come_out",1,ob,0);
	return HIC"你仔细观看这儿的景色。\n"NOR;
}

void come_out(object ob,int stage)
{
	object obj,obj2;

	tell_object(ob,out_msg[stage]);
	if( ++stage < sizeof(out_msg) )
        {
        call_out("come_out", 2, ob, stage );
                return;
        }
	obj2=new("/d/hangzhou/npc/obj/book8");
	obj2->move(ob);
	tell_object(ob,"少年对你嫣然一笑，把一本书交给你，也不说话。\n");
	add("count",-1);
	obj=new("/d/hangzhou/npc/cloudg");
	obj->move(environment(ob));
}

int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail(HIC"你沉浸在美丽的景色中，哪里还挪得动脚。\n"NOR);
	tell_object(ob,GRN"你恋恋不舍地离开了这儿。\n"NOR);
	return 1;
}