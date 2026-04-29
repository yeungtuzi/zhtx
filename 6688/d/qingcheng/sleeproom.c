// Room: /class/qingcheng/sleeproom.c

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
	set("short", "女弟子休息室");
	set("long", @LONG
这是专门给青城女弟子休息用的房间，房间不大，仅能摆下三个
小床，房间北边有一个大窗户，微风吹来，你觉得非常的舒畅。靠
门的墙边有个小茶几.
LONG
	);
	set("lighting", 60);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"tearoom",
		]));
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("no_faint",1);
	set("family","青城派");
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"obj/tao" : 3,

		]));

	setup();
}
