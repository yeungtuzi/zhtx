// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "仆役卧室");
        set("long", @LONG
    这里是在水烟阁从事杂役的仆佣所住的卧室，房间相当宽敞，东西
向一张大通铺最少可以睡二、三十人，东首一张大炕(bed)是冬天才用
的，因为有不少仆役回家过冬，所以比床铺稍小，北边开了几扇窗子，
南边则是摆放仆役私物的橱柜。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/waterfog/fwest3",
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
