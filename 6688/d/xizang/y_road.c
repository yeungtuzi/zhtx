// /d/xizang/y_road.c

inherit ROOM;

void create()
{
        set("short", "石场小路");
        set("long", @LONG
这里是采石工开出的一条小路,斜斜向下延伸,不知道通往什么地方.小路
两旁都是陡峭的悬崖(cliff).
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"y_road1",
  "northeast" : __DIR__"work",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
