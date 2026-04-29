// /d/xizang/road2.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这是一条弯弯曲曲的小路,路上虽然还有些积雪,但已不是十分寒冷,从
这里往东南是个山谷.
LONG
        );
        set("exits", ([
       "northup" : __DIR__"road1",
     "southeast" : __DIR__"road3",
]));
        setup();
        replace_program(ROOM);
}
