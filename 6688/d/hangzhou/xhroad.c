//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"柳荫路"NOR);
        set("long", @LONG
	  沿湖边有一条柳荫路，路上情人如织，见人来了也不避开。路
边草长莺飞，偶尔从堤边的湖水中跃起一两条鱼，溅起点点水花。
LONG
        );
        set("exits", ([ 
	  	"north" : __DIR__"bgate",
  		"south" : __DIR__"h_wjl",
	]));
        set("outdoors", "hangzhou");
        setup();
}
/*int valid_leave(object who,string dir)
{   
   	if( userp(who) && random(4) )
   	{
   		who->move(this_object());
   		return notify_fail(""); 
   	}
   	return 1;
}*/