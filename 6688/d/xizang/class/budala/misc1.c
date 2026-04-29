// /d/xizang/class/budala/misc1.c

inherit ROOM;

void create()
{
        set("short", "杂役房");
        set("long", @LONG
这里是为布达拉宫的工作的工匠杂役们居住的地方,有些脏乱.
LONG
        );
        set("exits", ([
          "south" : __DIR__"path3",
]));
        setup();
        replace_program(ROOM);
}
