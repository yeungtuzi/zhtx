//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西山大道");
	set("long", @LONG
	西山大道是联结曲院风荷与西湖乡，花港观鱼的纽带。道路很宽
敞，游人甚多。连几岁的孩童，年迈的老妇都出动了。西湖乡在西边，花
港观鱼在东北方向。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_xslu", 
	"west" : __DIR__"h_xhx",
	"southeast" : __DIR__"h_xslu3",
	 ]) );
	set("objects",([
	__DIR__"npc/kid" : 2,
	__DIR__"npc/oldw" : 1,
	]));
	
        setup();
}


