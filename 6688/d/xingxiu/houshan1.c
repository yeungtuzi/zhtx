// Room: /d/xingxiu/houshan1.c

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
	set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"room1",
  "west" : __DIR__"houshan2",
  "east" : __DIR__"houshan3",
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "southdown" : (: look_door,     "southdown" :),
]));
	set("objects", ([
		__DIR__"npc/xiezi" : random(2),
		__DIR__"npc/wa" : random(2),
		__DIR__"npc/spider" : random(2),
		__DIR__"npc/wugong" : random(2),
]));

	set("outdoors", "xingxiu");
	create_door("southdown", "后门", "northup", DOOR_CLOSED);

	setup();
	replace_program(ROOM);
}
