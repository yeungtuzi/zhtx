// /d/xizang/class/budala/ustair3.c
inherit ROOM;

void create()
{
        set("short", "台阶");
	set("long", @LONG
这里是布达拉宫讲经房后的台阶,通往后殿.
LONG
        );
        set("exits", ([
		"northup" : __DIR__"backhall",
	      "southdown" : __DIR__"lecture",
]));
        set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
