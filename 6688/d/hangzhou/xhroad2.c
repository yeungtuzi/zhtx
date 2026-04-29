//xhroad2.c
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIM"柳荫路"NOR);
        set("long", @LONG
	  沿湖边有一条柳荫路，路上情人如织，见人来了也不避开。路
边草长莺飞，偶尔从堤边的湖水中跃起一两条鱼，溅起点点水花。
LONG
        );
        set("exits", ([ 
	  	"east" : __DIR__"tgate",
  		"northdown" : __DIR__"diaoyt",
	]));
        set("outdoors", "hangzhou");
        setup();
}
/*int valid_leave(object who,string dir)
{   
   	if( userp(who) && random(2))
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}*/