// /d/xizang/class/gold_wh/cyard.c

inherit ROOM;

void create()
{
        set("short", "殿前广场");
        set("long", @LONG
这里是密宗金轮派札什伦布寺中央大殿前的广场,东,西,南三面有甬道通往别
处,北边是金碧辉煌的中央大殿.
LONG
        );
        set("exits", ([
		 "west" : __DIR__"pathw",
		 "east" : __DIR__"path",
		"north" : __DIR__"chall",
		"south" : __DIR__"paths",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
