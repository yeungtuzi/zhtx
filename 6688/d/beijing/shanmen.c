// Room: /u/p/pock/bj/shanmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"寿华门"NOR);
	set("long", @LONG
皇宫中采用庭园式的建筑结构。每到一个大殿或者三宫六院之前，肯定有
一道大门，而每道大门一般都会冠以相近的大殿或者宫的名字。这里靠近宁寿
宫，故叫寿华门。东边是上书房，一般苏拉太监是不能去的。北边是宁寿宫，
西边是则是养华门。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"shngong",
		"west" : __DIR__"yhmen",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
