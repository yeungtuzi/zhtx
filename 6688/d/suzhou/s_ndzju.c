// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"女弟子休息室"NOR);
	set("long", "这是供镖局中女弟子休息的地方。\n");
	set("sleep_room",1);
	
	set("exits",([
	"east" : __DIR__"bjhyuan",
	"west" : __DIR__"s_ndzju2.c",
	]));

	setup();
	replace_program(ROOM);
}
