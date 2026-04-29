#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", CYN"西单北大街"NOR);
	set("long", @LONG
你在挤拥的西单北大界上艰难地行走着。这里有比较发达的手工业作坊，
带动了整个地区的商业，旅业，饮食业的发展。这里可以说是京城最为繁荣的
地区之一了。来往的人很多，吆喝声，叫卖声源源不断地传来，使人感到十分
的厌烦，如果你不想浪费时间，还是赶紧离开这里吧。
LONG
	);
        set("outdoors", "bj");

	set("exits", ([
		"north" : __DIR__"xisi",
		"south" : __DIR__"xidan",
	]));
	setup();
	replace_program(ROOM);
}


