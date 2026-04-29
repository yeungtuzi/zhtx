// Room: /u/p/pock/bj/guodao2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"过道"NOR);
	set("long", @LONG
一条三米宽的青石铺砌的过道，它连接着宫中的各个宫殿，过道上每隔五米 
就有一盏气死风灯，用来晚上照明。每隔十步，则又有大铜缸一口，里边装满了
水，用于走火时救火之用。 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"qqmen",
		"south" : __DIR__"guodao",
		]));
	set("outdoors", "bj");
	setup();
	replace_program(ROOM);
}
