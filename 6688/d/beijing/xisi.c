// Room: /u/p/pock/bj/xisi.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[36m西四北大街[2;37;0m");
	set("long", @LONG
一条长长的街道从南边西单一直延伸到北边去，人街道上人还是那么多。
东边就是京城有名的如归客栈了。到京城游玩或办事的商旅都愿意在这里歇
脚。客栈的店小二正站在客店门口点头哈腰地招呼进出的客人。这里的服务
的确是京城最好的。从出来的客人脸上满意的笑容你可以充分肯定这一点。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"east" : __DIR__"kedian1",
		"south" : __DIR__"xidan1",
		"north" : __DIR__"xisi2",
		]));
	set("outdoors", "bj");

	setup();
	replace_program(ROOM);
}
