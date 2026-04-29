//xihu4.c
//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{      
	set("short", HIM"花心亭"NOR);
	set("long", @LONG
	  你来到西湖湖心的花心亭，放目一望，只见晴空万里，长烟
一空，近处荷香扑鼻，锦鳞游泳，远处沙鸥翔集，鱼歌互答，亭中大理
石桌子上正懒洋样地躺着一个人，只见他正把酒临风，不甚快哉。 亭名
是大仙小霖起的，也许是隐映了他自己花心好色之意。
LONG
	);    
	set("exits", ([
		"westdown" : __DIR__"h_styy2", 
		"eastdown" : __DIR__"h_styy3", 
		"south" : __DIR__"diaoyt",
	]));
	set("objects", ([
	__DIR__"npc/xiaolin" : 1,
	//"/class/guard/npc/xiaolin" : 1,
	]));       
	set("no_cast", 1);

	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="westdown" || dir=="eastdown")
	{
		tell_object(ob,HIC"你寻上一艘小艇，进入了湖中湖。\n"NOR);
		return 1;
	}
	if(dir=="up")
	{
		if(!ob->query_temp("save_lucy/braver"))
			return notify_fail("你不能上小霖的空中楼阁。\n");
		return 1;
	}
	return 1;
}