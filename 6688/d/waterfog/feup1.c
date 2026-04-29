// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "东侧厅");
        set("long", @LONG
这里是水烟阁东侧厅的二楼，由於侧厅是挑高建筑，因此这里只有
一条约七、八尺宽的走道连接楼梯与往西的门。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/waterfog/fcenter",
  "down" : "/d/waterfog/feast2",  
]));
        set("outdoors", "snow");
        set("objects", ([
             "/d/waterfog/npc/redguard":2
             ]) );
   
        setup();
        replace_program(ROOM);
}
