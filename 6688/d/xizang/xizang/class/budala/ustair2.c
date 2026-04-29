// /d/xizang/class/budala/ustair2.c
inherit ROOM;

void create()
{
        set("short", "台阶");
	set("long", @LONG
这里是布达拉宫断事司后的台阶,通往讲经房.达赖喇嘛通常就在那里讲经
说法.
LONG
        );
        set("exits", ([
		"northup" : __DIR__"lecture",
	      "southdown" : __DIR__"duan",
]));
        set("outdoors", "xizang");
	setup();
        replace_program(ROOM);
}
