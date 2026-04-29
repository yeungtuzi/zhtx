// Room: /u/p/pock/bj/aobai6.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "鳌拜卧房");
	set("long", @LONG
	这是鳌拜的卧房。鳌拜躺在床上睡着了，粗声粗气地打着呼噜。 
北边是鳌拜的书房，门一扇木门虚掩着，你看不清楚里边有什么东西。
不过象鳌拜这样的一介武夫，居然会拥有一个书房，的确有点奇怪，或
许有什么秘密呢！。 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"aobai3",
		"north" : __DIR__"aobai7",
			]));
	set("item_desc", ([ /* sizeof() == 2 */
		"door" : "这是一扇极厚的木门。\n",
		"north" : (: look_door,     "north" :),
		]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/aobai" : 1,
		]));
	set("no_clean_up", 0);
	create_door("north", "木门", "south", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if(dir == "north" && objectp(present("ao bai", environment(me))))
		return notify_fail("鳌拜挡住了你。\n");
      return ::valid_leave(me, dir);
}