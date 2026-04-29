// Room: /d/suzhou/bjdting.c
//modified by tlang
//97.12 

         
#include <ansi.h>
inherit C_GUILD;

void create()
{
	set("short", YEL"镖局大厅"NOR);
	set("long", @LONG
这是镖局大厅，副总镖头在这儿，一些富人正在这儿和他谈生意。厅内有几张桌子，
几把椅子，桌子上放着些茶，点心。在这儿可以加入(join)镖局。西边不远处的侧厅
外是镖局中人专用的驿站。
LONG
	);

	set("exits", ([
		"south" : __DIR__"lwchang",
		"north" : __DIR__"bjhyuan",
		"west" : __DIR__"gstart",
	]));

	set("objects", ([
		__DIR__"npc/jiang" : 1,  
		__DIR__"npc/furen" : 2,
	]));
        set("valid_startroom", 1);
        setup();
}

