//cuiyun.c 翠云宫
//by emote
#include <room.h>
inherit ROOM;

void create()
{
	set("short","翠云宫");
	set("long",
@LONG
翠云宫是华山上最大的建筑群之一，是两层的四合院式的建筑，正中的
大殿供奉三圣母，也就是民俗中二郎神的妹妹，沉香劈华山救的母亲。左右
的侧店供奉了一些山神和土地。
    你看见西边有个小门，那里似乎能出去的样子。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"lianhua",
		"west" :  __DIR__"fupishi",
		]));
        create_door("west", "旧木门", "east", DOOR_CLOSED);
	setup();
	
}