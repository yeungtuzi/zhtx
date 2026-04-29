// /d/xizang/octo5.c

inherit ROOM;

void create()
{
        set("short", "路口");
        set("long", @LONG
这里是大招寺外八角街西边的一个路口,一条小路从这里蜿蜒通向城
外绵延起伏的群山.远远地可以听到铁锤敲打石头的声音, 看来不远处有
个采石场.
LONG
        );
        set("exits", ([
  "east" : __DIR__"octo4",
  "west" : __DIR__"octo6",
  "south" : __DIR__"xiaolu",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);

}
