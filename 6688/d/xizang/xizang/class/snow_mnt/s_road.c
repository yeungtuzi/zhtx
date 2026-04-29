// /d/xizang/s_road.c

inherit ROOM;

void create()
{
        set("short","小路");
        set("long",@LONG
这里是雪山脚下的一条小路,北边是翻越大雪山的山路,那也是由成都去往大招
寺的唯一通道,西南边是一片草原,穿过草原再走一段土路就到了藏东最大的寺院雪
山寺.
LONG
        );

        set("outdoors","xizang");
        set("exits",([
                "north" : "/d/xizang/xueshan0",
//                "north" : "/u/m/mscat/xizang/xueshan0",
            "southwest" : __DIR__"caoyuan",
        ]));
        setup();
        replace_program(ROOM);
}
