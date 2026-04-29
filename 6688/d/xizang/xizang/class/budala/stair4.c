// /d/xizang/class/budala/stair4.c

inherit ROOM;

void create()
{
        set("short", "台阶");
        set("long", @LONG
这里是去布达拉宫的台阶.不少膜拜的人摇着转经筒,沿着台阶一步
一个头地磕过去.
LONG
        );
        set("exits", ([
     "southdown" : __DIR__"stair3",
        "westup" : __DIR__"stair5",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
