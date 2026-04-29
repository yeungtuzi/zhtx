// /d/xizang/house2.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这里是一座简陋的民宅,住着一户穷苦的藏民.
LONG
        );
        set("exits", ([
  "north" : __DIR__"octo11",
]));
        set("objects", ([
                __DIR__"npc/zkid" : 1,
                __DIR__"npc/zwoman" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
