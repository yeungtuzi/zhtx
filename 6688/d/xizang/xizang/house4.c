// /d/xizang/house4.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这里是一座简陋的民宅,住着一户穷苦的藏民.
LONG
        );
        set("exits", ([
  "east" : __DIR__"octo7",
]));
        set("objects", ([
                __DIR__"npc/zhuoma" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
