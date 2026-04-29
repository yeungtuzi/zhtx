//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "五云山麓");
	set("long", @LONG
	这儿是五云山麓，四处一色绿树葱葱，偶尔一棵树下有几颗石头，
石头旁边开着不知名的小花。西边往上远远地可以看见一片竹海。东北方
向传来巨大的轰隆声，大概是潮又起了。
LONG
        );
        set("exits", ([
	"westup"  : __DIR__"h_wyshan2", 
	"northeast" : __DIR__"h_hroad2",
	 ]) );
	
        setup();
}

int valid_leave(object ob,string dir)
{
	if(dir=="westup")
	{
		if(random(4)<2)
			return notify_fail("你往前走着，两边的景色没有什么变化。\n");
		tell_object(ob,HIM"你好象走进了一片云雾之中，不由得一呆。\n"NOR);
		return 1;
	}
	tell_object(ob,HIC"一阵惊天动地的响声传来，"NOR+YEL"吓了你一跳。\n"NOR);
	return 1;
}