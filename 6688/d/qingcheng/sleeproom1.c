// Room: /open/p/pock/sleeproom.c

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "男弟子休息间");
	set("long", @LONG
这是专门给青城男弟子休息用的房间，房间不大，仅能摆下三个
小床，房间北边有一个大窗户，微风吹来，你觉得非常的舒畅。靠
门的墙边有个小茶几.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
                "east":__DIR__"tearoom",
	]));
        set("sleep_room",1);
        set("family","青城派");
         set("no_faint",1);
        set("no_clean_up", 0);
	set("objects",([
		__DIR__"obj/teapot":1,
			]));
	setup();
}
