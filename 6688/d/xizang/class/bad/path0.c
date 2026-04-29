// /d/xizang/class/bad/path0.c

inherit ROOM;

void create()
{
        set("short", "小径");
	set("long", @LONG
这里是巨岩缝隙间一条弯弯曲曲的小径,仅可容一人侧身勉强而行.
LONG
);
	set("exits", ([
		"northup" : __DIR__"entrance",
		"southwest" : __DIR__"path1",
	]));
	set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
