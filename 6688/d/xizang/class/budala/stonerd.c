// /d/xizang/class/budala/stonerd.c

inherit ROOM;

void create()
{
        set("short", "青石板路");
        set("long", @LONG
这是一条上坡路,北边就是去布达拉宫的台阶.不少膜拜的人摇着转经
筒,沿着台阶一步一个头地磕过去.
LONG
        );
        set("exits", ([
          "south" : __DIR__"corner",
        "northup" : __DIR__"stair1",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
