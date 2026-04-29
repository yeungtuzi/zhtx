//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short",HIM"湖中湖"NOR);
	set("long", @LONG
	  这是三潭影月岛中间的一个小湖，有袖珍玲珑之美。湖中没有荷
花，连荷叶也没有，但是湖水清澈见底，可以看见游鱼嘻闹。湖中心有一个
美丽的亭子，里面有人。
LONG
	);    
	set("exits", ([
		"eastup" : __DIR__"huaxint", 
		"westup" : __DIR__"h_styy",
	]));
	
	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="eastup")
	{
		tell_object(ob,HIC"你跳下小艇，进了中心的小亭。\n"NOR);
		return 1;
	}
	if(dir=="westup" )
	{
		tell_object(ob,HIC"你跳下小艇，到了湖中湖边的陆地上。\n"NOR);
		return 1;
	}
	return 1;
}