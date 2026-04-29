//by tlang

#include <ansi.h>
inherit ROOM;

void search_grass(object ob,int stage);
string look_grass();

string *npcs = ({
        "xiaolu",
        "yetu",
        "xiaohou",
	"snake",
});

string *search_msg=({
	YEL"你开始仔细搜索这儿的草丛......\n"NOR,
	"			\n",
});

void create()
{
	int i = random(sizeof(npcs));

	set("short", GRN"树林"NOR);
	set("long", @LONG
	这是一片茂盛的树林，里面有各种野兽跑来跑去，十分惹人喜欢。
你正看得出神，突然一只小鹿从你身边跳过，你伸手想抓住它，却没有抓
上。西北方向有一片草特别茂盛，里面仿佛有什么在动。
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
	        "east" : __DIR__"s_hssm",
	]));

        set("objects", ([
	"/d/suzhou/npc/"+npcs[i] : 1
	]));
	set("item_desc",([
	"grass" : (: look_grass :),
	"草" : (: look_grass :),
	]));

	set("count",1);
	set("trigger",3);                                    
	setup();
}

string look_grass()
{
	return "一片深可及项的草丛。\n";
}

void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object ob=this_player();
	
	if(!arg || arg!="grass")
		return notify_fail("你要搜查什么？\n");
	if(ob->query("sen")<=50)
		return notify_fail("你的精神太差了，没法搜查。\n");
	call_out("search_grass",1,ob,0);
	ob->start_busy(5);
		return 1;
}


void search_grass(object ob,int stage)
{
	object obj;
	int my_sen;

	my_sen=ob->query("sen");

 	tell_object(ob, search_msg[stage]);
        if( ++stage < sizeof(search_msg) )
        {
        call_out("search_grass", 5, ob, stage );
                return;
        }
	if( query("count")<1 )
	{
			write("你什么也没有搜到。\n");	
				return;
	}	
	if(!ob->query_temp("looking/wine") )
	{
		if(query("trigger")<1 || ob->query_temp("search/grass") )
		{
			write("你什么都没有搜到。\n");
			return;
		}
		ob->set_temp("search/grass",1);	
		add("trigger",-1);
		ob->add("potential",2);
		ob->start_busy(2);
		write("一个人影从草丛中窜出来，飞快地跑了。。。。。\n");
		ob->receive_damage("sen",my_sen*1/3);
			return;
	}
	add("count",-1);
	obj=new("/d/suzhou/npc/obj/lihua");
	obj->set("can_apply",1);
	obj->move(environment(ob));
	write("一个和尚从草丛中窜出来，飞快地跑了，却掉了一样东西。\n");
	ob->receive_damage("sen",my_sen*1/3);
}