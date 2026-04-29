// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"侧房"NOR);
	set("long", @LONG
	这是男性家丁睡觉的地方。有几张床，几把椅子。看上去虽然不怎么
气派，却也顺眼。	
LONG
);
	set("exits",([
	"east" : __DIR__"s_zqt",
	]));

	set("sleep_room",1);

	setup();
	replace_program(ROOM);
}
