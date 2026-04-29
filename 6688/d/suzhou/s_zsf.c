// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"书房"NOR);
	set("long", @LONG
	这儿简直是书的海洋，只见书架上，桌子上，椅子上，茶几上，还有
炕上，都堆满了书。一位老先生正在书堆中诵读诗书，见了人也不知道招呼。	
LONG
);
	set("exits",([
	"west" : __DIR__"s_zzt",
	]));

	set("sleep_room",0);
	set("objects",([
	__DIR__"npc/s_zsy" : 1,
	]));

	setup();
	replace_program(ROOM);
}
