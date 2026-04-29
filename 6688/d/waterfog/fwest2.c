// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "西侧厅");
        set("long", @LONG
    这里是水烟阁西侧的厅院，一道白石梯从这里通往二楼，往北是仆
役的卧房跟柴房，南边是出水烟阁的侧门，往西则是一个可以眺望山谷
的阳台。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/waterfog/fwest3",
  "south" : "/d/waterfog/fwest1",
  "up" : "/d/waterfog/fwup1",  
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
