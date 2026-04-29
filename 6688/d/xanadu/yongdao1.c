// 幽明山庄
// by yeung. All rights reserved.

inherit "/std/room/doom.c";

void create()
{
	set("short", "幽明山庄");
	set("long", @LONG
	此时天色已暗，庄门裂开，只见这座破旧的庄院深邃阔大，不
知至何处终止。前面一条长长的甬道，已被白雪所覆盖，一路通往庄院。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"yongdao2",
	  "south" : __DIR__"gate",
	]));                                     

        set("blocks", ([
		  "south" : "yuwen xiu",
		  "north" : "yuwen xiu",
	]));
	
	set("objects", ([
			__DIR__"npc/yuwenxiu" : 1,
		])
	);

	setup();
}
