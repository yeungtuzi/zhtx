// Room: /u/p/pock/bj/xidan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[36m西单[2;37;0m");
	set("long", @LONG
这里就是西单，人来人往，十分热闹。游人虽然多，但大都只四处晃悠, 
着东瞅瞅西看看，也不急着买什么。西边有家杂货铺，去那里买东西的人很多。 
不断有人从北边走来，似乎那里也挺热闹。南边是十里长街。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"xidan1",
		"south" : __DIR__"aobai1",
		]));
	set("outdoors", "bj");

	setup();
	replace_program(ROOM);
}
