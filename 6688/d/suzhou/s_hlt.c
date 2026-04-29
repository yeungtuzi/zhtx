// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"葫芦庙后庭");
	set("long", @LONG
	后庭长满了齐腰深的荒草，微风吹过，草波起伏，仿佛有什么东西在里
面蠕动。两边是客房，好象住着有人。
LONG
);

	set("exits",([
	"south" : __DIR__"s_hld",
	"east" : __DIR__"s_hlf",
	"west" : __DIR__"s_hlf2",
	]));
	
	setup();
	replace_program(ROOM);
}
