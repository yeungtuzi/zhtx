// Room: /d/waterfog/sroad3.c

inherit ROOM;

void create()
{
        set("short", "水烟阁正门");
        set("long", @LONG
    这里是水烟阁的正门，一股沁人心脾的檀香使你精神为之一振，正
门共分三进，全部都是上等的檀木雕成，最里的门上悬著一块匾额，上
面龙飞凤舞地写著几个大字，可是你全然看不出到底是什麽字。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "north" : "/d/waterfog/guildhall",
  "south" : "/d/waterfog/sroad3",
  "east" : "/d/waterfog/feast1",
  "west" : "/d/waterfog/fwest1",
]));
        set("outdoors", "snow");
        set("objects", ([
             "/d/waterfog/npc/tiger":1,
             "/d/waterfog/npc/guard":2
             ]) );
   
        setup();
        replace_program(ROOM);
}
