// /d/xizang/class/budala/platform.c

inherit ROOM;

void create()
{
        set("short", "后殿平台");
        set("long", @LONG
这里是布达拉宫后殿外的平台,站在这里可以看到南面的拉萨市街与北面巍峨
起伏的山峰.
LONG
        );
        set("exits", ([
		"southdown" : __DIR__"backhall",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
