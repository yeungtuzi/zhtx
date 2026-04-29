// /d/xizang/xueshan4.c

inherit ROOM;

void create()
{
        set("short", "雪山西麓");
        set("long", @LONG
这里是大雪山西麓,由此往西就是藏族聚居的地方,往东翻过大雪山
可以到成都.
LONG
        );
        set("exits", ([
 "westdown"  : __DIR__"xueshan5",
   "eastup"  : __DIR__"xueshan3",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
