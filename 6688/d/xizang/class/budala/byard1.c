// /d/xizang/class/budala/byard1.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是布达拉宫后殿外的后院,西边是存放历代活佛灵骨的塔群,东边是后殿.
LONG
        );
        set("exits", ([
           "east" : __DIR__"backhall",
           "west" : __DIR__"tower",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
