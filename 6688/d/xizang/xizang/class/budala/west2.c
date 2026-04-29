// /d/xizang/class/budala/west2.c

inherit ROOM;

void create()
{
        set("short", "西侧殿");
	set("long", @LONG
这里是布达拉宫西侧殿.
LONG
        );
        set("exits", ([
          "north" : __DIR__"treasure",
	  "east" : __DIR__"wpath3",
]));
        setup();
        replace_program(ROOM);
}
