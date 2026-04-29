// /d/xizang/class/budala/uproad1.c

inherit ROOM;

void create()
{
        set("short", "宫前街上坡");
        set("long", @LONG
这是一条上坡路,北边山上就是布达拉宫辉煌的建筑群.
LONG
        );
        set("exits", ([
        "west" : __DIR__"corner",
 "southdown" : "/d/xizang/uproad",
//   "southdown" : "/u/m/mscat/xizang/uproad",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
