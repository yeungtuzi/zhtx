//      guangchang.c 广场
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/guangchang.c

inherit ROOM;

void create()
{
        set("short","广场");
        set("long",@LONG
这里是雪山寺内的广场。广场的北面就是依山而建的雪山寺大殿。
寺内有一些手持木禅杖的守寺喇嘛在巡逻。
LONG
        );

        set("outdoors","xizang");

        set("exits",([
                "east" : __DIR__"xiaoyuan",
                "west" : __DIR__"chang",
                "north" : __DIR__"dadian",
                "south" : __DIR__"shanmen",
        ]));

        set("objects" , ([
                __DIR__"npc/xslama1"  : 4 ,
        ]));

        setup();

}

int valid_leave(object me, string dir)
{
        if ( me->query("id") == "guardlm1" &&  dir == "south" ) return 0;
        return ::valid_leave(me, dir);
}
