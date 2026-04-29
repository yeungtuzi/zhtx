// /d/xizang/class/budala/backhall.c

inherit ROOM;

void create()
{
        set("short", "后殿");
        set("long", @LONG
这里是布达拉宫后殿,两边是后院.
LONG
        );
        set("exits", ([
          "northup" : __DIR__"platform",
	"southdown" : __DIR__"ustair3",
	     "west" : __DIR__"byard1",
	     "east" : __DIR__"byard2",
]));
        setup();
        replace_program(ROOM);
}
