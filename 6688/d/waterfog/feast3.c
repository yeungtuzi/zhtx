// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是水烟阁的厨房，东首一座大灶，灶边堆著许多瓦□，北边是
一张方桌，桌上锅碗瓢盆一应俱全，西边则是一个橱柜，往南可以回到
厅中。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
   "south" : "/d/waterfog/feast2",
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
