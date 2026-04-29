//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "黄龙吐翠");
	set("long", @LONG
	园中满是杏黄色的垂柳，偶尔在一角也露出一点秀丽可人的青青翠
竹，微风吹来，柳条随风起舞，翠竹为之喝彩倾倒，频频点头，似乎已经陶
醉了，你也陶醉了。
LONG
        );
        set("exits", ([
	"west"  : __DIR__"h_hld2",
	 ]) );

	set("objects", ([
		__DIR__"npc/oldguy" : 1,
        ]) );

        setup();
}

	