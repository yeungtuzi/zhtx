//      hubian3.c 湖边小路
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/hubian3.c

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
    这是圣湖边的小路。
LONG
        );

        set("outdoors","xizang");

        set("exits",([
                "north" : __DIR__"hubian4",
                "southwest" : __DIR__"hubian2",
        ]));

        setup();
        replace_program(ROOM);
}
