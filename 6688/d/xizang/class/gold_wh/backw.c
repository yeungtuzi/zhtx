// /d/xizang/class/gold_wh/backw.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是后殿西边的走廊,通往藏经阁,北边是一座禅房.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"backhall",
		 "west" : __DIR__"cangjing",
		"north" : __DIR__"chouse1",
]));
        setup();
	replace_program(ROOM);
}
