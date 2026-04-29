// /d/xizang/m_road.c

inherit ROOM;

void create()
{
        set("short", "冰川");
        set("long", @LONG
这里是雪山上万年不化的冰川.
LONG
        );
        set("exits", ([
   "northwest" : __DIR__"m_road1",
      "eastup" : __DIR__"peak",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
