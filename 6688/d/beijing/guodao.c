// Room: /u/p/pock/bj/guodao.c

inherit ROOM;

void create()
{
	set("short", "[1;35m过道[2;37;0m");
	set("long", @LONG
一条三米宽的青石铺砌的过道，它连接着小院与后宫，过道上每隔五米 
就有一盏气死风灯，用来晚上照明。每隔十步，则又有大铜缸一口，里边装 
满了水，用于走火时救火之用。 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"nanku",
		"south" : __DIR__"houyuan",
		"north" : __DIR__"guodao2",
	]));
	set("outdoors", "bj");

	setup();
	replace_program(ROOM);
}
