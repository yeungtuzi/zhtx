#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"过道"NOR);
	set("long", @LONG
一条三米宽的青石铺砌的过道，它连接着小院与后宫，过道上每隔五米
就有一盏气死风灯，用来晚上照明。每隔十步，则又有大铜缸一口，里边装
满了水，用于走火时救火之用。
LONG
	);
        set("outdoors", "bj");
	set("exits", ([
		"north":__DIR__"guodao2",
		"south":__DIR__"houyuan",
	]));

	setup();
	replace_program(ROOM);
}

