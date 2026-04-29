// /d/jingcheng/yamen.c
// Dongsw Created in 2002 4

inherit ROOM;

void create()
{
        set("short", "朝阳门");
        set("long", @LONG
  高墙巍峨，长梁雕龙，飞檐画凤，这里就是“朝阳门”
。往里就是皇宫大门了，一般的百姓到此截然止步，不敢擅
自逾越皇家禁地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao1",
                  "south" : "/d/jingcheng/wumen",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
                "/quest/killer/suqier" : 1,
        ]));

        setup();
        replace_program(ROOM);
}



