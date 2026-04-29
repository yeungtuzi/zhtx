//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"桃源岭"NOR);
	set("long", @LONG
	古人道:人间四月芳菲尽,山寺桃花始盛开.由此可以看出一点:
山里的春色四季不衰,让人留恋不已.这岭不高,但却有几分险.所以西湖
游人虽然多,到这儿来的却不多.山道上偶尔能见到一个少年,倔强地往
岭上攀登.下山可就容易多了.
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_yfen", 
	"westup"  : __DIR__"h_tyl2",
	"southwest" : __DIR__"h_lylu",
	 ]) );
	
	setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="westup")
	{
		if(random(3)<2)
			return notify_fail("你费力地走在山道上，周围的景色没有多大变化。\n");
		if(ob->query("kee")>4 )
		{
			ob->receive_damage("kee",random(4));
			ob->set_temp("pending/braver",1);
			ob->start_busy(1);
			return 1;
		}
		ob->set_temp("pending/braver",1);
		ob->start_busy(1);
		return 1;
	}
	return 1;
}
	

