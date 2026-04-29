// 幽明山庄
// by yeung. All rights reserved.

inherit "/std/room/doom.c";

void create()
{
	set("short", "小连环坞");
	set("long", @LONG
	这里是幽明山庄三十里外的小连环坞，这小小连环坞水道十三里十三
道，错综迷离，不明底细者很容易迷路。前面是一间小小的客栈，再往前走就
到了渡口了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	  "northwest" : __DIR__"inn",
	  "south" : "/d/road/luoyang",
	]));                                     
/*
	set("objects", ([
			__DIR__"npc/yuwenxiu" : 1,
		])
	);
*/
	setup();
}
