// /d/xizang/class/gold_wh/rest.c

inherit ROOM;
#include "/std/room/check_room_family.c"

void create()
{
        set("short", "休息室");
        set("long", @LONG
这里是札什伦布寺大殿的西厢房,供本寺弟子休息.外间屋有茶水供应,这里备
有床榻可以小憩.
LONG
        );
        set("exits", ([
		"south" : __DIR__"west",
]));
        set("sleep_room",1);
        set("family","布达拉宫");
        set("no_faint",1);
        set("no_fight",1);
        set("no_poison",1);
        set("no_magic",1);
	setup();	
}
