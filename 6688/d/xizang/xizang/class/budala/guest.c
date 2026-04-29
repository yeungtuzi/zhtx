// /d/xizang/class/budala/guest.c

inherit ROOM;

void create()
{
        set("short", "客人休息室");
	set("long", @LONG
这里是供外客休息的地方.
LONG
        );
        set("exits", ([
		"south" : __DIR__"sj1",
	]));
	setup();
//        replace_program(ROOM);
}
