// by tlang
//baozhu hall
// 97.12

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", YEL"宝珠山庄大厅"NOR);
	set("long", "厅内迎面先看见一个赤金九龙青地大匾，上书三个字“宝珠\n"
"堂”，后有一行小字：某年月日，书赠朱八太爷。大紫香木案几上，设有三尺来高\n"
"的珊瑚，上悬吴道子的飞天图。庄主的好友段飞熊正在厅中。\n");
	set("no_sleep_room",0);
	set("outdoors","hangzhou"); 
	set("exits", ([
		"west" : "/d/hangzhou/huay",
]));  

	set("objects", ([
		__DIR__"npc/duanfx" : 1,
]));
	setup();
}   
    
