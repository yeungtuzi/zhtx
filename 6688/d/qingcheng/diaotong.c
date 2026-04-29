// diaotong.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"吊桶中"NOR);
        set("long", @LONG
一个小小的吊桶，整个人憋在这里，你感到非常的难受.
LONG
        );
        set("exits",([
        	"out":__DIR__"well",
		]));
 
           set("no_magic",1);
        setup();
}   
void init()
{	add_action("do_burn","burn");
}
 /*
void boat_run(object me)
{	me=this_player();
	message("vision","吊桶在井水上漂着，虽然没有下沉，但不断地在摇晃...\n",this_object());
		call_out("boat_run",20,me);  
		return;
}
int do_burn(object me)
{	me=this_player();
	message_vision(HIB"$N的符纸和所画的符咒被井水泡湿了，点不着!! "NOR+MAG" ^_*\n"NOR,me);
	return 1;
}
 */
