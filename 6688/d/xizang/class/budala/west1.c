// /d/xizang/class/budala/west1.c

inherit ROOM;

void create()
{
        set("short", "西侧殿");
	set("long", @LONG
这里是布达拉宫西侧殿.
LONG
        );
        set("exits", ([
          "west" : __DIR__"wpath3",
	  "east" : __DIR__"lecture",
]));
        setup();
        replace_program(ROOM);
}
