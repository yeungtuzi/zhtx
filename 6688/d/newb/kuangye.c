inherit __DIR__"newbie_room";

void create()
{
        set("short", "旷野");
        set("long", @LONG
这里是无尽的旷野，天地一体，坦坦荡荡，前方大路渐渐明朗。
后方归路渐渐消无。
LONG
        );

        set("no_fight",1);
        set("objects", ([
                        __DIR__"npc/boy2": 1,
                ]));
        setup();
}

