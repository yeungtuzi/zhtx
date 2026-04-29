// /d/xizang/class/budala/byard2.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是布达拉宫后殿外的后院,西边是后殿,东边是一列石头小屋.
LONG
        );
        set("exits", ([
           "east" : __DIR__"stone1",
           "west" : __DIR__"backhall",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
