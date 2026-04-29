//      shanlu2.c 山路
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/shanlu2.c

inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG
    这是一条上山的小路。
LONG
        );
        set("outdoors","xizang");
        set("exits",([
                "northup" : __DIR__"shanmen",
                "eastdown" : __DIR__"shanlu1",
        ]));

        setup();
        replace_program(ROOM);
}
// 增加雪山寺守卫
