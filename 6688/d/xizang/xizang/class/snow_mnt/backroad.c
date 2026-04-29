// /d/xizang/backroad.c

inherit ROOM;

void create()
{
        set("short","山路");
        set("long",@LONG
这里是雪山脚下的一条小路,北边是翻越大雪山的山路,那也是由成都去往大招
寺的唯一通道,南边掩映在群山中的金碧辉煌的院落传来阵阵梵唱,正是雪山寺.
LONG
        );

        set("outdoors","xizang");
        set("exits",([
              "northup" : "/d/xizang/xueshan1",
                "south" : __DIR__"houmen",
        ]));
        setup();
//        replace_program(ROOM);
}

