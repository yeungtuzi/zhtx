// /d/xizang/class/gold_wh/east.c

inherit ROOM;

void create()
{
        set("short", "东厢");
        set("long", @LONG
这里是札什伦布寺大殿的东厢房,供朝拜的香客休息.在这里有茶水供应,北边
另有一个房间备有床榻.
LONG
        );
        set("exits", ([
		"south" : __DIR__"path",
		"north" : __DIR__"guest",
]));
	set("resource/water",1);
        setup();
	replace_program(ROOM);
}
