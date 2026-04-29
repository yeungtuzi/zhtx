// /d/xizang/class/gold_wh/backe.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是后殿东边的走廊,东边是一个平台,北边是一座禅房.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"watch",
		 "west" : __DIR__"backhall",
		"north" : __DIR__"chouse2",
]));
        setup();
	replace_program(ROOM);
}
