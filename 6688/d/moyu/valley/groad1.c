
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
路的两旁，有各式各样的树木，千奇百怪，还有些不知名的花草。可以想象
在阳光普照的时候，这山谷一定很美。
LONG
	);
	set("exits", ([
                "south" : __DIR__"valley_entrance",
                "northeast" : __DIR__"groad2",
	]));
	setup();
	replace_program(ROOM);
}
