//by tlang
       
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "寒山寺门");
	set("long", "一座古刹，远远的就可以看见大门的匾上用金色油漆写着"+
"\n\n		"+YEL"寒山寺"NOR+"\n\n		\n"+
"三个大字。庙门大开，两名小和尚站在门口接待香客。寺庙西边\n"
"不远处有座林子，里面好象有什么东西在动。\n");
	set("exits", ([
		"north" : __DIR__"s_hssqt",
		"southdown" : __DIR__"szroad15",
		"west" : __DIR__"s_trees",
]));   
	set("objects",([
	__DIR__"npc/monk" : 2,
	]));
                         
	setup();
}





