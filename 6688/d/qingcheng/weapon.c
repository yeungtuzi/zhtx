// Room: /open/hihi/weaponor.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"兵器店"NOR);
	set("long", @LONG
这里是一个小小的兵器屋，但麻雀虽小，五脏俱全。兵器的种类倒是很多。
如果你想闯荡江湖，不妨先来这买些防具和武器，以作为防身杀敌之用。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"jie31",
		]));
	set("objects", ([ /* sizeof() == 1 */
//                  __DIR__"npc/weaponor" : 1,
                "u/z/zephyr/weaponor" : 1,
		]));

	setup();
	replace_program(ROOM);
}
