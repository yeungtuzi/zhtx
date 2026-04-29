// jiushi.c

inherit ROOM;

void create()
{
        set("short", "酒室");
        set("long", @LONG
只见这间屋里摆满了各式各样的酒瓶，酒杯和酒桶。刚一进门
就闻到一阵扑鼻的酒香，是人不禁醺醺然起来。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"zoulang1",
]));
        
        set("objects", ([
                (__DIR__"npc/danqingsheng"):1,
                ]));
        setup();
        replace_program(ROOM);
}
    