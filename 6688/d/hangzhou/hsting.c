//hsting.c
//by dwolf
//97.11.8
  
#include <ansi.h>
inherit ROOM;
           
string do_look();
void create()
{
	set("short", "浣纱亭");
	set("long", @LONG
	  这就是著名的浣纱亭，相传当初西施曾经在这儿浣过纱，于是今
人建此亭以为纪念。这儿已经到了西湖边了，从这儿可以看见亭外(outside)
美丽的景色。几个小女孩正在亭边浣纱，让人不由怀念起西施。
LONG
	);
	set("exits", ([
		"south" : __DIR__"h_kezhan",
]));
        set("objects", ([
                  __DIR__"npc/girl"  : 2,
]));   
	set("item_desc", ([
		"outside" : (: do_look :),
]));
	setup();
}     

string do_look()
{
	return "亭外风景如画，荷花的香气不停地飘过来。\n";
}
