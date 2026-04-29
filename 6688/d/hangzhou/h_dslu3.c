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
        set("short", "德胜大街");
	set("long", @LONG
	你走在一条热闹但祥和的街道上,只见两边满是小摊,上面摆满了
各种各样的东西.外地来的游人,本地的姑娘姨子们都围着,或者讨价还价,
或者一饱眼福,看看希奇.
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_dslu2", 
	"south"  : __DIR__"h_wlgc",
	 ]) );

	set("objects", ([
		__DIR__"npc/"+npcs[i] : 2,
        ]) );
 
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(4)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}
*/
	