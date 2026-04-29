// /d/xizang/small_r0.c

inherit ROOM;

void create()
{
        set("short", "小路");
	set("long", @LONG
这里是一条弯弯曲曲的小路,不知道通向哪里.
LONG
        );
        set("exits", ([
                "west" : __DIR__"small_r",
	       "south" : __DIR__"grassland4",
	]));
        set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
