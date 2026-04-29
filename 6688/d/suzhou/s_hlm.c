// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"葫芦庙门");
	set("long", @LONG
	这是一座出名却破落的小庙，香火少的可怜，门口连一个接待香客的知客
僧也没有。
LONG
);

	set("exits",([
	"south" : __DIR__"s_slx2",
	"north" : __DIR__"s_hld",
	]));

	setup();
	replace_program(ROOM);
}
