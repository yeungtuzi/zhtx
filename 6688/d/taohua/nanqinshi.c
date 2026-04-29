// Room: /d/new_taohua/nanqinshi.c
// Date: YZC 96/01/19
//write by lysh

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "男寝室");
	set("long", @LONG
这里是男寝室。靠墙一溜摆着几张木床，床上
有柔软的被褥，让人一看就想睡。
LONG
	);
        set("family","桃花岛");
        set("no_faint",1);
	set("sleep_room",1);

	set("exits", ([
		"south" : __DIR__"yushimen",
		
	]));

	setup();
}



