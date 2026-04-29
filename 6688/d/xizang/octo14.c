// /d/xizang/octo14.c

inherit ROOM;

void create()
{
        set("short", "路口");
        set("long", @LONG
这里是八角街通往布达拉宫的路口,北边是热闹非凡的宫前街,一家杂货
店的招牌从西边斜伸出来.八角街往东西两边延伸.
LONG
        );
        set("exits", ([
  "west" : __DIR__"octo13",
 "north" : __DIR__"gongqian",
  "east" : __DIR__"octo15",
]));
        set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
