// /d/xizang/class/budala/stair1.c

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
      "southdown" : __DIR__"stonerd",
         "eastup" : __DIR__"stair2",
]));
        set("outdoors", "xizang");
	set("objects", ([
		__DIR__"npc/xiangke" : 2+random(3)
	]));
        setup();
        replace_program(ROOM);
}
