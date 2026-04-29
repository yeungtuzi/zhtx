//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short",HIC"三潭映月"NOR);
	set("long", @LONG
	  这是西湖三岛中最大的岛，有“小瀛洲”之称，四周是环型
堤埂，岛中有湖，湖中有岛，被誉为水上仙子。岛南湖面上有三座石塔
鼎足而立，造型别致，明月当空时，月影，塔影，云影溶成一片，充满
诗情画意。
LONG
	);    
	set("exits", ([
		"eastdown" : __DIR__"h_styy2", 
		"northdown" : __DIR__"xihu3",
	]));
	
	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="eastdown")
	{
		tell_object(ob,HIC"你寻上一艘小艇，进入了湖中湖。\n"NOR);
		return 1;
	}
	if(dir=="northdown")
	{
		tell_object(ob,HIC"你寻上自己的小艇，继续游览。\n"NOR);
		return 1;
	}	
	return 1;
}