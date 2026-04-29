// /d/xizang/templeh2.c

inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
这里是大招寺内的一间禅房,北边有一个大洞.
LONG
        );
        set("exits", ([
  "north" : __DIR__"wallhole",
  "south" : __DIR__"bigyard",
]));
        setup();
        replace_program(ROOM);
}

//int valid_leave
