// /d/xizang/class/budala/stair6.c

inherit ROOM;

void create()
{
        set("short", "台阶");
        set("long", @LONG
这里是去布达拉宫的台阶.不少膜拜的人摇着转经筒,沿着台阶一步
一个头地磕过去.北边就是布达拉宫的正门.
LONG
        );
        set("exits", ([
      "eastdown" : __DIR__"stair5",
       "northup" : __DIR__"foregate",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
