//      kedian.c 客店
//      Designed by secret (秘密)
//      97/04/08

inherit ROOM;

void create()
{
        set("short","客店");
        set("long",@LONG
这里是土路边的小客店,东边的山路可以通往雪山,翻越雪山是去西藏的
方向,另外一个方向通往中原.南边是雪山的圣湖, 远处山坡上金碧辉煌的寺
院传来阵阵梵唱,正是雪山寺.
LONG
        );

        set("valid_startroom",1);

        set("exits",([
                "east" : __DIR__"tulu2",
        ]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
