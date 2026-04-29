//      caoyuan.c 草原
//      Originally Designed by secret (秘密)
//      97/04/08
//      modified by mscat
// /d/xizang/caoyuan.c

inherit ROOM;

void create()
{
        set("short","草原");
        set("long",@LONG
这里是雪山脚下的一片草原。草原北面是起伏的群山，山顶上积着终年不化的白
雪，因此得名大雪山。西边有一条土路不知道通往哪里。
LONG
        );

        set("outdoors","xizang");

        set("exits",([
                "west" : __DIR__"tulu1",
                "northeast" : __DIR__"s_road",
        ]));

        set("objects",([
                NPC_DIR"yetu" : random(4),
        ]));

        setup();
        replace_program(ROOM);
}
