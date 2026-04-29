// /d/xizang/class/gold_wh/rest.c

inherit ROOM;

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
        setup();
//	replace_program(ROOM);
}
