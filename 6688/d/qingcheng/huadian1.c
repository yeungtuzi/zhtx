// Room: /open/hihi/huadian1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"花店"NOR);
	set("long", @LONG
  这是一个花店，专门做四季鲜花生意的.特别是现在临近本镇大庆,
来买花的青年人非常多.再加上花店女老板又年轻,又漂亮。所以店铺虽然
小,生意却异样的火红.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "west" : __DIR__"jie21",
		]));
	set("objects",([
		__DIR__"npc/flowboss.c":1,
		]));

	setup();
	replace_program(ROOM);
}
