//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short",HIM"三潭映月"NOR);
	set("long", @LONG
	 这是西湖三岛中最大的岛，有“小瀛洲”之称，四周是环型堤
埂，岛中有湖，湖中有岛，被誉为水上仙子。岛南湖面上有三座石塔鼎足
而立，造型别致，明月当空时，月影，塔影，云影溶成一片，充满诗情画
意。
LONG
	);    
	set("exits", ([
		"westdown" : __DIR__"h_styy3", 
		"northdown" : __DIR__"xihu4",
		"northeast" : __DIR__"xihu6",
	]));

	set("objects",([
	__DIR__"npc/wennuan" : 1,
	]));
	
	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="westdown")
	{
		tell_object(ob,HIC"你寻上一艘小艇，进入了湖中湖。\n"NOR);
		return 1;
	}
	if(dir=="northdown" || "northeast")
	{
		tell_object(ob,HIC"你寻上自己的小艇，继续游览。\n"NOR);
		return 1;
	}
	return 1;
}