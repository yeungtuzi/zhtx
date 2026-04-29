//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "月轮山脚");
	set("long", @LONG
	你来到钱塘江边月轮山下，远远地可见山上一座塔呈六合状，有几
分雄壮，有几分清秀，让人抨然心动。东边不远是个十字路口，车水马龙，
十分热闹。	
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_cross", 
	"west" : __DIR__"h_hroad2",
	"southup" : __DIR__"h_lht2",
	 ]) );
	
        setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="southup")
	{
		if(random(4)<2)
			return notify_fail("你往山上爬着，四周的景色没有什么变化。\n");
		tell_object(ob,HIC"你眼前一亮，原来你已经来到了山上。\n"NOR);
		return 1;
	}
	return 1;
}