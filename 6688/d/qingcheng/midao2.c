// 密道
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIB"密道"NOR);
	set("long", @LONG
前面终于出现一道光明，漫长的密道走到了尽头.
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"midao",
                "west":__DIR__"shulin",
	]));
     setup();
 	}
int valid_leave(object me, string dir)
	{
	if( userp(me) && dir == "east" )
		message_vision("$N双手摸索着向地道深处走去.\n",me);

	return 1;
}
