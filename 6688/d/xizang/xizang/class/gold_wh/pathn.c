// /d/xizang/class/gold_wh/pathn.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是中央大殿北边的甬道,通往后殿.
LONG
        );
        set("exits", ([
		"north" : __DIR__"backhall",
		"south" : __DIR__"chall",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
