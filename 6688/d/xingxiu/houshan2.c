// Room: /d/xingxiu/houshan2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "后山");
	set("long", @LONG
这里杂草灌木丛生，又潮湿又阴冷，稍不留神就碰到了各种各样的毒虫，看来还是
赶紧离开这个地方的好！
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houshan1",
]));
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/xiezi" : random(2),
		__DIR__"npc/wa" : random(2),
		__DIR__"npc/spider" : random(2),
		__DIR__"npc/wugong" : random(2),
]));


	set("outdoors", "xingxiu");
	setup();
	replace_program(ROOM);
}
