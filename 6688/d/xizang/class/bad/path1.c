// /d/xizang/class/bad/path1.c

inherit ROOM;

void create()
{
        set("short", "小径");
	set("long", @LONG
这里是一条弯弯曲曲的小径,南边是个开阔的峡谷,暖风送来阵阵花香,东北边
是嶙峋的巨石,小径渐行渐窄,没入石丛中.
LONG
);
	set("exits", ([
		"northeast" : __DIR__"entrance",
		"south" : __DIR__"gate",
	]));
	set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
