// /d/xizang/class/budala/stair2.c

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
      "westdown" : __DIR__"stair1",
        "eastup" : __DIR__"stair3",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
