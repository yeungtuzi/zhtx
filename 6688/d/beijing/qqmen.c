// Room: /u/p/pock/bj/qqmen.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIM"乾清门"NOR);
	set("long", @LONG
乾清门是乾清宫前的一到大门楼，门的西边就是太后居住的寝宫了。门的里边
有一扇大屏风，挡住了你的视线。你看不了乾清宫里边的东西。没有太后的懿旨是
不能随便进去的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"guodao3",
		"south" : __DIR__"guodao2",
		"west" : __DIR__"qqgong",
		]));
	create_door("west","乾清门","east",DOOR_CLOSED);
	set("outdoor","bj");
	setup();

}
