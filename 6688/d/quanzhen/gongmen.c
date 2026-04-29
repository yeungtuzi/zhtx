// Room: /u/hacky/quanzhen/gongmen.c
// Made by: hacky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "[31m宫门[2;37;0m");
	set("long", @LONG
这是全真派重阳宫的宫门,这里整个由大块的青石铺成，极为平坦。
但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来.
门前站着一位知客道长,北边遥遥可以望见一个高大的宫殿.
LONG
	);
    set("valid_startroom",1);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sanqingdian.c",
  "south" : __DIR__"shijie8.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhike" : 1,
]));
     set("outdoors","quanzhen");
    setup();
   "/obj/board/quanzhen_b"->foo();
}
