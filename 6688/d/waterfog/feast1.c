// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "水烟阁东侧花厅");
        set("long", @LONG
这里是水烟阁正门东边的花厅，东边和南边围著一圈白石栏杆，栏
杆外种著许多茶花，往西是水烟阁的正门，往北则是东侧的侧厅，往东
则是天邪弟子的睡房，从这里可以看见通往二楼的阶梯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/waterfog/feast2",
  "west" : "/d/waterfog/entrance",
  "east" : __DIR__"bedroom",
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
