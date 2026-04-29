// /d/jingcheng/yamen.c
// Dongsw Created in 2002 4

inherit ROOM;

void create()
{
        set("short", "皇宫走廊");
        set("long", @LONG
    这是一条走廊。房顶一侧支在西面的高墙上，彩梁画栋，
连顶棚也用彩漆绘满了各种飞天的图形，每幅精美的雕画似乎
都在诉说一个娓娓动人的故事。
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao2",
                "east" : __DIR__"hubu",
                "west" : __DIR__"libu",
                "south" : __DIR__"chaoyang",
        ]));

        setup();
        replace_program(ROOM);
}


