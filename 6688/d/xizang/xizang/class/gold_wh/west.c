// /d/xizang/class/gold_wh/west.c

inherit ROOM;

void create()
{
        set("short", "西厢");
        set("long", @LONG
这里是札什伦布寺大殿的西厢房,供本寺弟子休息.在这里有茶水供应,北边另
有一个房间备有床榻.
LONG
        );
        set("exits", ([
		"south" : __DIR__"pathw",
		"north" : __DIR__"rest",
]));
	set("resource/water",1);
        setup();
	replace_program(ROOM);
}
