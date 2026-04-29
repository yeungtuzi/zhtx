// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "精进楼");
	set("long", @LONG
		穿过一道垂花门，就是镖局弟子借书阅览的地方。地上放满
了武功秘籍，一位镖头坐在门口，看样子书是防止外人进来。这房间出乎意料
地大，所以尽管在这儿读书的人很多，却一点也不挤。
LONG
	);
	set("no_fight",1);
	set("objects",([
	__DIR__"npc/biaotou3" : 1,
      	__DIR__"npc/obj/book" : 1,
	]));
	set("exits",([
	"out" : __DIR__"school",
	]));

	setup();
	replace_program(ROOM);
}
