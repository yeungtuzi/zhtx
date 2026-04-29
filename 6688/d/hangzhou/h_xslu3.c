//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西山大道");
	set("long", @LONG
	西山大道是联结曲院风荷与西湖乡，花港观鱼的纽带。路很宽
敞，游人甚多。连几岁的孩童，年迈的老妇都出动了。东南方向有个港
口非常热闹。	
LONG
        );
        set("exits", ([
	"northwest"  : __DIR__"h_xslu2", 
	"southeast" : __DIR__"h_hxgy",
	 ]) );
	set("objects",([
	__DIR__"npc/kid" : 2,
	__DIR__"npc/oldw" : 1,
	]));
	
        setup();
}

int valid_leave(object ob,string dir)
{
//	if(random(4)<2)
//		return notify_fail("你往前走着，两边的景色没有多大变化。\n");
	if(dir=="southeast")
	{
	tell_object(ob,HIC"一阵花香扑鼻而来，你精神顿时振作起来。\n"NOR);
		return 1;
	}
	return 1;
}