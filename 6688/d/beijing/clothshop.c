// Room: /u/p/pock/bj/clothshop.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"裁衣店"NOR);
	set("long", @LONG
一间小小的裁衣店，小店干净整洁，并没有因为是裁衣店，店里就撒满了布碎什么的。
店老板正在忙碌着改做衣服。。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"changjie3",
		]));
	set("objects",([
		__DIR__"npc/tailor":1,
		]));
	setup();
	replace_program(ROOM);
}
