// /d/jingcheng/yamen.c
// Dongsw Created in 2002 4

inherit ROOM;

void create()
{
        set("short", "礼部大堂");
        set("long", @LONG
        这里就是礼部尚书办公的地方，房间不大，但甚是小巧巍峨
诸多士兵分列两旁，当中有一把御赐太师椅，上面做着尚书大人，雪白
的墙壁配上大理石地板，显示出大堂的巍峨。
LONG
        );

        set("exits", ([
                "east" : __DIR__"dadao1",
        ]));

        set("objects", ([
//                __DIR__"npc/shangshu_libu" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


