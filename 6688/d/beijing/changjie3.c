// changjie2.c
// written by pock 98/09/04

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", CYN"十里长街"NOR);
	set("long", @LONG
这是一条宽阔的青石街道，向东西两头延伸。北边是一家裁衣店，南边
是一家铁匠铺，打铁的叮叮咚咚的声音不断传来，看来是一个殷实勤奋的好
铁匠。
LONG
	);
        set("outdoors", "bj");

	set("exits", ([
		"west" : __DIR__"changjie2",
		"south" : __DIR__"smith",
		"east" : __DIR__"changjie4",
		"north" : __DIR__"clothshop",
	]));
	set("objects", ([

	]));

	setup();
	replace_program(ROOM);
}

