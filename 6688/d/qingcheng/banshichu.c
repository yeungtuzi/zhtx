// Room: /open/hihi/banshichu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"镖局办事处"NOR);
	set("long", @LONG
这里是镖局的办事处，地方不大，一个大柜台差不多占了整个房间的一半空间。
柜台后面坐着一个帐房先生，负责处理事务，办理护镖走镖的登记工作。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"bj",
	  "south" : __DIR__"lianwuting",
		]));
//	set("objects", ([ /* sizeof() == 1 */
//		  __DIR__"npc/zhangfang" : 1,
//		]));
	setup();
	replace_program(ROOM);
}
