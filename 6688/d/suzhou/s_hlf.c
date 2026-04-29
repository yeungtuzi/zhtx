// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"葫芦庙客房");
	set("long", @LONG
	房间里满是灰尘，一个小和尚拿着扫帚，在那儿一个人发呆。他也是
房间中的唯一一个活物，甚至可以说是唯一一个物体，因为房间中除了他，连
老鼠，椅子都没有。
LONG
);

	set("exits",([
	"west" : __DIR__"s_hlt",
	]));
	
	set("objects",([
	__DIR__"npc/s_monk" : 1,
	]));

	setup();
	replace_program(ROOM);
}
