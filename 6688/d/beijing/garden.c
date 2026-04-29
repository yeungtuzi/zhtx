// Room: /u/p/pock/bj/garden.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"御花园"NOR);
	set("long", @LONG
这里是皇宫中的御花园，虽然皇上也曾叫人种植各种奇花异草，但有些因为气候
的不适宜，不能在北方寒冷的天气。所以也就放弃了这种计划，现在御花园中没有当
令的鲜花，只见一片的碧绿。最为奇特的可以说是那株相思树了。这棵树已经很大年
纪了，但两个树干盘旋而长，不见丝毫老态。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"shngong",
		"east" : __DIR__"road",
	]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
