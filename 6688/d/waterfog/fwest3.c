// Room: /d/waterfog/fwese.c

inherit ROOM;

void create()
{
        set("short", "柴房");
        set("long", @LONG
    这里是一间柴房，一捆一捆劈好的柴薪都整齐地堆放在柴房北侧，   
留下一条通道通往东边仆役的卧室。往南可以回到水烟阁的西侧厅。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/waterfog/fwest2",
  "east" : "/d/waterfog/fwbed",
]));
        set("outdoors", "snow");
//        set("objects", ([
//             "/daemon/class/fighter/tiger":1,
//             "/daemon/class/fighter/guard":2
//             ]) );
   
        setup();
        replace_program(ROOM);
}
