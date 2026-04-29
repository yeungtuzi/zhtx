// /d/xizang/xiaolu.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是一条崎岖不平的小路,往北是八角街,西南边是一个忙碌的采石场.
LONG
        );
        set("exits", ([
            "north" : __DIR__"octo5",
        "southwest" : __DIR__"work",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);

}
