//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"西湖乡"NOR);
	set("long", @LONG
	这是杭州盛产鲜鱼的地方，西湖的糖醋鱼虽然甲天下，但做糖醋
鱼的所用的鲜鱼都是西湖乡的小伙子，大姑娘们一大早从这儿送过去的。
因为西湖中水清，如果谁在湖中打鱼，恐怕会被骂死的。
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_xslu2", 
	"southwest" : __DIR__"h_ljlu",
	 ]) );
	
	set("objects",([
	__DIR__"npc/fishboy" : 1,
	__DIR__"npc/fishgirl" : 1,
	]));

        setup();
}

