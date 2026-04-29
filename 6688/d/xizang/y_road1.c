// /d/xizang/y_road1.c

inherit ROOM;

void create()
{
        set("short", "石场小路");
        set("long", @LONG
这里是采石工开出的一条小路,斜斜向下延伸,可以看到南边不远处是一个
山谷,隆隆水声从那里传来.
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"yvalley",
  "northeast" : __DIR__"y_road",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
