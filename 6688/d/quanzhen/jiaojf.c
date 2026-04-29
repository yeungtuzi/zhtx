// Room: /u/kiss/quanzhen/jiaojf.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"校经房"NOR);
	set("long", @LONG
这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长方
形的大桌子，上面也堆满了书。几个道童正在整理书籍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang10.c",
]));
        set("objects", ([
          __DIR__"npc/daotong1.c" : 2,
          __DIR__"npc/obj/jing.c" : 2,
         ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
