inherit ROOM;

void create()
{
        set("short", "皇宫正门");
        set("long", @LONG
    这便是皇宫正门。巍峨雄伟的城墙上，'紫禁城'三个大字十分显眼，
气势辉煌。许多官兵立在两旁。
LONG
        );

        set("exits", ([
                  "north" : "/d/jingcheng/wumen",
                  "south" : "/d/jingcheng/bdj3",
        ]));

        set("objects", ([
                __DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


