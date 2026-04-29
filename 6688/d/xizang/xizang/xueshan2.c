// /d/xizang/xueshan2.c

inherit ROOM;

void create()
{
        set("short", "雪山半腰");
        set("long", @LONG
这里是由川入藏必经的大雪山,从这里往上爬,很快就要到达雪山之
顶,当然也是更冷.
LONG
        );
        set("exits", ([
 "westup"    : __DIR__"xueshan3",
 "eastdown"  : __DIR__"xueshan1",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
