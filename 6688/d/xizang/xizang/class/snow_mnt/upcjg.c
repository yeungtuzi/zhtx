// /d/xizang/class/snow_mnt/upcjg.c

inherit ROOM;

void create()
{
        set("short", "藏经室二楼");
        set("long", @LONG
这里是雪山寺的藏经室的二楼，一位老尼住在这里清修。
LONG
        );

        set("exits", ([
		"down" : __DIR__"cangjingge",
        ]));

        set("objects", ([
		__DIR__"npc/ni" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
