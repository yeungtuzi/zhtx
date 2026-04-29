//lou2.c 
//by dwolf                   

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"吹雪二楼"NOR);
        set("long", @LONG
	  这儿完全是用檀香木打造的。一阵阵的檀香飘过来.使你心旷神夷。厅口
悬着一幅字画, 写道：“是非成败转头空，青山依旧在，几度夕阳红。”一位神情潇
洒的老者正休闲的坐在书桌前，拿着本书悠闲地看着。他旁边有道梯子，似乎通向一
个神秘的地方。
LONG
        );
        set("exits", ([
        "down" : __DIR__"lou.c",
	"up" : __DIR__"myhell.c",
        ]));
	set("objects",([
	"/class/guard/npc/quester" : 1,
	]));

      	setup();
}

int valid_leave(object who,string dir)
{
	if(!who->query("can_pass1") && dir=="up" )
		return notify_fail("一种神秘的力量阻止了你。\n");
	return 1;
}
            



                                                
