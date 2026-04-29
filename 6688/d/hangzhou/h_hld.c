//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"h_girl",
	"woman",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", "黄龙洞甬道");
	set("long", @LONG
	路边有一块标志，上面写着：此处往北千米到黄龙洞。路上行人甚
多，十分热闹。道边的小草已经齐腰深了，更有一些灌木，长得非常茂盛，
放眼环顾，满眼皆是一片绿。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_hld2", 
	"southeast"  : __DIR__"h_lft",
	 ]) );

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1,
        ]) );
 
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有明显的变化。\n");
	return 1;
}*/	