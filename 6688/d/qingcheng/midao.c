// 密道
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIB"密道"NOR);
	set("long", @LONG
黑漆漆的密道，你不知道要走多久才能出去。
LONG
        );
	set("exits", ([ 
		"east" : __DIR__"mishi1",
		"west" : __DIR__"midao2",
	]));
    setup();
}
int valid_leave(object me, string dir)
{
	if( userp(me) )
    	message_vision("$N双手摸索着向地道深处走去.\n",me);

    return 1;
}
void init()
{
	add_action("do_go","go");

}

int do_go()
   {
   if(random(5)){
     message_vision("$N双手摸索着向地道深处走去.\n",this_player());
     this_player()->move(this_object());
     return 1;
   }
}

