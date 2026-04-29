//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short", YEL"孤山"NOR);
	set("long", @LONG
	  孤山上有为纪念北宋隐逸诗人林和靖而建的放鹤亭，此处多梅，
比比皆是。孤山之外，但见风帆凡鸟，烟云缥缈，似送夕阳，迎素月，让
人忘了人间烟火。
LONG
	);    
	set("exits", ([
		"eastup" : __DIR__"h_ybl",
		"westdown" : __DIR__"xihu6", 
	]));
	set("objects", ([
	__DIR__"npc/h_girl" : 2,
	]));

	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="westdown")
	{
		tell_object(ob,HIC"你寻上自己的小艇，继续游览。\n"NOR);
		return 1;
	}
	if(dir=="eastup")
	{
		tell_object(ob,HIC"你登上了月波楼。\n"NOR);
		return 1;
	}
	return 1;
}