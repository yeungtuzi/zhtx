// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "聆啸厅");
        set("long", @LONG
这里是水烟阁二楼的聆啸厅，南面是一个大露台，按著西、西南、
南、东南、东等方向立著五块灰绿色的怪石(stone)，东西各有一个出
口通往侧厅，往北则是水烟阁主所居的春秋水色斋。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/waterfog/feup1",
  "west" : "/d/waterfog/fwup1",  
  "north" : "/d/waterfog/fpalace",
]));
        set("outdoors", "snow");
        set("objects", ([
 		__DIR__"npc/watcher":1,
             ]) );
   
        setup();
        replace_program(ROOM);
}
