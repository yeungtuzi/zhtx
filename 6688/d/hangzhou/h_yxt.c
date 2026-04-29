//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"一线天"NOR);
	set("long", @LONG
	这儿当真险恶的吓人，没有轻功根底的人休想上去。往上几乎是成
九十度的倾斜度，两边则是深不可测的山涧。偶尔有白云从你脚下飘过，更
让你感到心惊胆战。
LONG
        );
        set("exits", ([
	"up"  : __DIR__"h_lysi", 
	"eastdown"  : __DIR__"h_lylu2",
	 ]) );
	set("count",5);	
	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="up")
	{
		if(!ob->query_skill("dodge") )
			return notify_fail("你没有轻功根底，还是小心一点，别上去吧。\n");
		if(query("count")>1)
		{	
			add("count",-1);
			tell_object(ob,HIC"你费力地爬了上去。\n"NOR);
			ob->improve_skill("dodge",random(15));
			ob->receive_damage("kee",15);
			return 1;
		}	
		tell_object(ob,RED"你小心翼翼地爬了上去。\n"NOR);
		return 1;
	}
	return 1;
}
	

