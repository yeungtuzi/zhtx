// /d/xizang/road3.c

inherit ROOM;

void create()
{
        set("short", "雪梅谷");
        set("long", @LONG
你眼前出现了一个山谷,西边高耸的山峦挡住了寒风,谷中风和日暖,栽满红
梅,盛开的红梅与四周的雪山相映,好似一片红霞自天而降.
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"road2",
   "eastdown" : __DIR__"road4",
]));

        setup();
        replace_program(ROOM);
}
// 这里增加一些故事情节
