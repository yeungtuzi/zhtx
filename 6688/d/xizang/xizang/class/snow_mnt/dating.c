//      dating.c 大厅
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/class/snow_mnt/dating.c

inherit ROOM;

void create()
{
        set("short","大厅");
        set("long",@LONG
    这里是寺内的大厅，几位有道的高僧在高声辩论。
LONG
        );

        set("exits",([
                "east" : __DIR__"zoulang1",
                "west" : __DIR__"zoulang2",
                "north" : __DIR__"zoulang3",
                ]));
        set("objects", ([
        	__DIR__"npc/seng" :2+random(5),
]));
        setup();
        replace_program(ROOM);
}
