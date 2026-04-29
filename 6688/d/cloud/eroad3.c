// Room: /u/cloud/eroad3.c

inherit ROOM;

void create()
{
        set("short", "绮云镇街道");
        set("long", @LONG
这里是绮云镇东头，北面是张家，东南方就是茶场。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"rich",
  "southwest" : __DIR__"eroad2",
  "southeast" : __DIR__"eroad4",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

