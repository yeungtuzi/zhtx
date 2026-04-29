//《鹿鼎记》
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short", HIM"月波楼"NOR);
	set("long", @LONG
	  楼有楼台通向水面，远吞山光，平挹江濑，幽静高雅，不可名
状。夏宜急雨，有瀑布声，冬宜密雪，有碎玉声。宜鼓琴，琴调和畅，宜
诵诗，诗韵清绝，宜围棋，子声丁丁然。。。。。。更有初冬之前，秋月
甫起，湖月影映，勾人心魄。
LONG
	);    
	set("exits", ([
		"westdown" : __DIR__"h_gushan",
	]));
	set("objects", ([
//	__DIR__"npc/h_dao" : 1,
//	__DIR__"npc/h_disc" : 1,
	]));
	
	set("count",1);

	setup();
}

void init()
{
	add_action("study_moon","study");
}

int study_moon(string arg)
{
	object obj;
	object ob=this_player();

	if(arg=="平湖秋月" || arg=="moon")
	{
		if(ob->query("sen")<=50)
		{
		tell_object(ob,"你的精神太差了，没法研究。\n");
			return 1;
		}
		if(!ob->query_temp("moon/dao") || !ob->query_temp("moon/disc") 
		|| random(3)<2 || query("count")<1 || ob->query_skill("literate",1)>=100 
		|| ob->query_skill("music",1)>=100 )
		{
		ob->receive_damage("sen",35);
		tell_object(ob,HIC"你仔细研究平湖秋月的景色，发现没有什么特别的地方。\n你失望地放弃了。。。。\n");
			return 1;
		}
		add("count",-1);
		ob->receive_damage("sen",40);
		tell_object(ob,"你仔细研究平湖秋月的景色，忽然进入一种幻想境界。。。。。。\n
				良久醒来，发现自己手上拿着一本书。\n");
		obj=new("/d/hangzhou/npc/obj/book13");
		obj->move(ob);
			return 1;
	}
	tell_object(ob,"你要干什么？\n");	
	return 1;
}


int valid_leave(object ob,string dir)
{
	tell_object(ob,HIC"你下了月波楼。\n"NOR);
		return 1;
}
