// /d/xizang/peak.c

inherit ROOM;

void create()
{
        set("short", "雪峰");
        set("long", @LONG
这里是雪山上的一座山峰,十分寒冷.
LONG
        );
        set("exits", ([
        "southdown" : __DIR__"mountain",
         "westdown" : __DIR__"m_road",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
