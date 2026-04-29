// /d/xizang/class/budala/east2.c

inherit ROOM;

void create()
{
        set("short", "东侧殿");
	set("long", @LONG
这里是布达拉宫东侧殿.
LONG
        );
        set("exits", ([
          "west" : __DIR__"epath3",
]));
        setup();
        replace_program(ROOM);
}
