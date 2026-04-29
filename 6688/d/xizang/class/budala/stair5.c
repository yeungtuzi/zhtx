// /d/xizang/class/budala/stair5.c

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
      "eastdown" : __DIR__"stair4",
        "westup" : __DIR__"stair6",
]));
        set("outdoors", "guanwai");
        set("objects",([
                "/class/gaibang/yu-hx":1,       
        ]));


        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
