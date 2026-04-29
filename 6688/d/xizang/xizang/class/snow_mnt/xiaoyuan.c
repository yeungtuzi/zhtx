//      xiaoyuan.c 小院
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/xiaoyuan.c

inherit ROOM;

void create()
{
        set("short","小院");
        set("long",@LONG
    这里是寺内的小院，北边有个厨房。
LONG
        );

        set("outdoors","xizang");

        set("exits",([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"chufang",
        ]));
	set("objects", ([
		__DIR__"npc/lingzhi" : 1,
	]));

        setup();
        replace_program(ROOM);
}
