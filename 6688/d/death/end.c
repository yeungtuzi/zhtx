// all is over!

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "时空终点");
	set("long", @LONG
       恍惚之间你来到了这个以前从来没有见到过的地方，一切都
如此的陌生，一切又如此的熟悉。一定是前世或者来生你所在的地方，
不管外面时光变幻，似乎在这里，一切都已经静止，或许，这就是每
个人得到最终解脱的地方。残阳如血，映着天际那一抹晚霞，你突然
意识到，
     
    这里，就是终结，一切都不再有意义，一切，都已经成为往事。
     
LONG
	);
	setup();
	set("no_fly",1);
	set("no_magic",1);
	set("no_fight",1);
}


void init()
{
	object me=this_player();
	add_action("do_quit","quit");	
	add_action("do_quit","summon");
	
	if( !wiz_level(me) && !is_wiz(me) )
	{
		me->start_busy(2000);
		me->set("env/invisibility",9);
		me->set("startroom",__FILE__);
		call_out("start_suicide",3,me);
	}

}	                                

int do_quit(string arg)
{
	write("一切，都不再有意义！\n");
	return 1;
}	         





