// /d/xizang/class/gold_wh/guest.c

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
这里是札什伦布寺大殿的东厢房,供朝拜的香客休息.外间屋有茶水供应,这里
备有床榻可以小憩.
LONG
        );
        set("exits", ([
		"south" : __DIR__"east",
]));
        setup();
//	replace_program(ROOM);
}
