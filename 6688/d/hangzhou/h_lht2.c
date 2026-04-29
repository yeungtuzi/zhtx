//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

string *npcs=({
	"ren",
	"ren2",
	"ren3",
	"h_girl",
	"h_girl2",
	"h_girl3",
});

void create()
{
	int i=random(sizeof(npcs));
        set("short", "六合塔");
	set("long", @LONG
	只见塔身凌空突起，跨陆俯江，登塔临槛，远眺钱塘江，风帆点点，
钱塘江石桥一虹飞架，一派绮丽风光尽收眼底。	
LONG
        );
        set("exits", ([
	"northdown" : __DIR__"h_lht",
	 ]) );
	set("objects",([
	__DIR__"npc/"+npcs[i] : random(2),
	__DIR__"npc/traveler" : random(2),
	]));
			
        setup();
}

int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你慢慢地往山下走着，四周的景色没有什么变化。\n");
	tell_object(ob,HIC"你走下了月轮山。\n"NOR);
	return 1;
}