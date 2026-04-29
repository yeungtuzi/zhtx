// /d/xizang/mroad2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一条被人走出来的小山路，虽然不宽却是够一辆马车通行。小路
顺着山中较为平坦地带缓缓向东西两边伸展。向南是一道高耸的绝崖。
LONG
        );
        set("exits", ([
   "west" : __DIR__"grassland0",
   "east" : __DIR__"mroad",
  "south" : __DIR__"cliff",
]));
        set("outdoors", "xizang");

        setup();
        replace_program(ROOM);
}

