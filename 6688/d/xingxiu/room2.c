// Room: /d/xingxiu/room2.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "星宿派总舵");
	set("long", @LONG
这里就是星宿派的总舵所在，屋内灯火通明，干燥暖和，正中虎皮大椅上躺着一人，
此人一定是星宿派掌门人丁春秋，众弟子立于四周,阿谀奉承之声此起彼伏！
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"droom",
  "south" : __DIR__"road1",
]));
	set("objects", ([
		CLASS_D("xingxiu")+"/ding" : 1,
		__DIR__"npc/boshou" : random(2),
		__DIR__"npc/haoshou" : random(2),
		__DIR__"npc/gushou" : random(2),
]));
	set("no_clean_up", 0);
	set("valid_startroom", "1");
	setup();                    
	"/obj/board/xingxiu_b"->foo();	
}

int valid_leave(object me, string dir)
{
	object ob;

	if( dir == "north" 
	&& (ob = present("ding chunqiu", environment(me)))
	&& living(ob)){
		message_vision(HIY"$N冷冷的看了$n一眼,一道杀机自眼中一闪而逝！\n"NOR, ob, me);
		return notify_fail("你停住了脚步。\n");
	}
	return ::valid_leave(me, dir);
}
