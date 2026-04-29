// /d/xizang/class/budala/trash.c

inherit ROOM;

void create()
{
        set("short", "垃圾场");
	set("long", @LONG
这里是布达拉宫脚下的垃圾场,到处一片脏乱.
LONG
        );
        set("exits", ([
		"east" : "/d/xizang/small_r",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
