// Room: /open/hihi/jie11.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"福州大街"NOR);
	set("long", @LONG
  走在福州大街上，你被周围的货物搞得眼花缭乱了。虽然福州开发的
晚一些，但因为东边东海的航运业非常的发达，所以带动了整个福州的发展。
这里到处都是一派欣欣向荣的景象。街道的东边有一个肉铺，西边是一个三
层的雄伟的酒店。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
	  "south" : __DIR__"jie21",
	  "north" : __DIR__"beimen",
	  "east" : __DIR__"roupu1",
	  "west" : __DIR__"inn",
	]));
	set("objects",([
		__DIR__"npc/eshao":1,
		__DIR__"npc/puren":2,
		]));

	setup();
	replace_program(ROOM);
}
