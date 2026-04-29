// Room: /u/p/pock/bj/west3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"西三所"NOR);
	set("long", @LONG
这里是西三所，其实就是皇宫在中轴线西边的三进小院，供宫中服杂役的
苏拉太监居住。再往西就是后宫了。往东通向养华门寿华门还有御花园等，再
往北一拐，出了神武门就可以出宫了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"yhmen",
		"west" : __DIR__"guodao3",
		]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
