// Room: /u/cloud/nwroad1.c

inherit ROOM;

void create()
{
        set("short", "北市场");
        set("long", @LONG
这里是绮云镇的北市场，再向北就是镇口了。
    一股茶香与腥膻相混合的气味扑鼻而来，西首铺子外挂着个牛头;
东面是家二层的茶楼，金字招牌十分晃眼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"butchery",
  "northwest" : "/d/road/rjdtodk3",
  "south" : __DIR__"nwroad2",
  "east" : __DIR__"tearoom",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}

