//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "湖岸");
	set("long", @LONG
	这是一条绕着西湖而建的碎石路,两边柳树垂阴,浅草没鞋.湖中
不时有渔波兴起,更有大胆的金鲤凌空跃起,在阳光下闪耀,让人看的心都
醉了.东边不远处有一座亭子.
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_hzxg", 
	"east"  : __DIR__"h_lft",
	 ]) );
	
        setup();
}

/*int valid_leave(object ob,string dir)
{
	if(random(3)<2)
		return notify_fail("你往前走着，两边的景色没有什么变化。\n");
	return 1;
}*/