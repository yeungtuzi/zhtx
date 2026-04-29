// Room: /u/p/pock/bj/yhmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"养华门"NOR);
	set("long", @LONG
皇宫中采用庭园式的建筑结构。每到一个大殿或者三宫六院之前，肯定有
一道大门，而每道大门一般都会冠以相近的大殿或者宫的名字。这里是养华门。
北边有个小小的养鱼养荷的水池，水池边上是一个小亭。往西通往西三所，往
东通往寿华门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"shanmen",
		"west" : __DIR__"west3",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
