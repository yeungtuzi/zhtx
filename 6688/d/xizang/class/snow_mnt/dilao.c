//      dilao.c 地牢
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/dilao.c

inherit ROOM;

void create()
{
        set("short","地牢");
        set("long",@LONG
    这是一个阴暗、潮湿的牢房。
LONG
        );

        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));

	set("objects", ([
		__DIR__"npc/secret" : 1,
	]));
        setup();
        replace_program(ROOM);
}
// 这里藏一个秘密
