// /d/xizang/class/bad/grass_h.c

#include <room.h>

inherit "std/room/shop.c";
//inherit NEWSHOP;

void create()
{
	set("short", "草庐");
	set("long", @LONG
这里是一座简朴但是十分整齐干净的草庐,住着白道江湖三位侠女.她们可能
算是最早来找十大恶人麻烦的白道人士了.几次试闯失败后,她们知道恶人谷中机
关密布,一时苦无良策,只好在谷外结庐暂居,等待时机.对于有志一闯恶人谷的江
湖豪客,她们时常也会提供一些武器粮食的帮助,或代为保存一时用不上的行李物
品.
LONG
);
	set("exits", ([
		"east" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/gadzooks" : 1,
		__DIR__"npc/waner" : 1,
		__DIR__"npc/easts" : 1,
	]) );
	setup();
}
