//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山间小路");
	set("long", @LONG
	山间的一条小路，道旁石头林立，却不险恶，各种藤蔓小草或绕着
，或伏着，更有许多灌木，劲松，使这儿成了绿色的海洋。路上行人甚多，
笑声正浓。
LONG
        );
        set("exits", ([
	"north"  : __DIR__"h_river2", 
	"eastdown" : __DIR__"h_hroad2",
	 ]) );
	set("objects",([
	__DIR__"npc/ren" : 1,
	__DIR__"npc/ren2" : 1,
	__DIR__"npc/ren3" : 1,
	]));
	
        setup();
}

int valid_leave(object ob,string dir)
{
//	if(random(4)<2)
//		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	if(dir=="eastdown")
	{	
		tell_object(ob,HIC"一阵惊天动地的响声传来，"NOR+YEL"吓了你一跳。\n"NOR);
		return 1;
	}
	return 1;
}