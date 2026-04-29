// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short","柴房");
	set("long", @LONG
	普普通通的一间柴房,堆满了柴草,这儿显然是严禁火烛的
LONG
	);

	set("exits", ([
		"west"  :__DIR__"dingfeng5.c",
	]));

    set("sleep_room",1);
    set("no_fight",1);
    set("no_faint",1);
    set("family","日月神教");
	setup();
}

