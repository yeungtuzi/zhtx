//      chanshi.c 禅室
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/chanshi.c

//inherit ROOM;

inherit ROOM;

void create()
{
        set("short","禅室");
        set("long",@LONG
这里是僧人门参禅打坐的地方。
LONG
        );

        set("no_fight",1);
//        set("sleep_room",1);
        set("no_steal",1);

        set("exits",([
                "west" : __DIR__"zoulang3",
        ]));

        setup();
        replace_program(ROOM);
}
