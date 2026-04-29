//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "玉皇巷");
	set("long", @LONG
	这条路通向玉皇山，相对而言，这儿的游人明显不如西湖边多，只有
一些香客上山进香。大家安安静静地走着，听不见一点喧哗，给人以庄严肃穆
的感觉。
LONG
        );
        set("exits", ([
	"northup"  : __DIR__"h_yhshan", 
	"south" : __DIR__"h_fxj2",
	 ]) );
	set("objects",([
	__DIR__"npc/xiang-ke" : 1,
	]));		
        setup();
}

int valid_leave(object ob,string dir)
{
	//if(random(4)<2)
		tell_object(ob,"你往前走着，不时越过一位香客。\n");
		return 1;
}
