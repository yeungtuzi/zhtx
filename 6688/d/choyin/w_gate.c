// Room: /d/choyin/s_gate.c

inherit ROOM;

void create()
{
        set("short", "乔阴县城西门");
        set("long", @LONG
这里是乔阴县城的西门，西门年久失修，显得古老斑驳。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
                "west" : "/d/road/rcstoyt4",
                "east" : __DIR__"w_street1",
        ]));
        set("objects", ([
                __DIR__"npc/cityguard": 2
        ]) );
        set("outdoors", "choyin");

        setup();
        replace_program(ROOM);
}
