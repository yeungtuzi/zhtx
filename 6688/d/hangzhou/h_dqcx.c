//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "断桥残雪");
	set("long", @LONG
	你沿着锦带桥往南走，不多久，桥梁中断，四周奇迹般地满是梅花
树，如果现在是冬天，那么这儿梅花盛开，看上去仿佛是雪花遍地一般，十
分冷艳。望湖中一望，远远地可见平湖秋月。
LONG
        );
        set("exits", ([
	"north" : __DIR__"h_wjl",
	 ]) );
	
        setup();
}

