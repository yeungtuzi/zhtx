// huashi.c

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这间屋的四壁上挂满了名家的书法名作，有颜真卿的《裴将军诗》，
三国蜀中大将张飞的《八蒙山铭》，更有怀素的狂草。显示出主人书法
鉴赏力的确是一流。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"zoulang1",
]));
        
        set("objects", ([
                (__DIR__"npc/tubi"):1,
         ]));               
        setup();
        replace_program(ROOM);
}
