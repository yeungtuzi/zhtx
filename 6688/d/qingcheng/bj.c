// Room: /open/hihi/bj.c
#include <ansi.h>
#include <room.h>
//inherit C_GUILD;
inherit ROOM;

void create()
{
	set("short", HIW"福威镖局大厅"NOR);
	set("long", @LONG
 你来到了镖局大厅，厅中的摆设非常的合理，家具古色古香，年代想必已经
很久远了。从这也可以看出镖局的先辈为了建好镖局付出了非常的努力。不知道
它的继承人能不能把它弄得更好。在这儿可以加入(join)镖局，北边不远处的侧
厅外是镖局中人专用的驿站。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
	  "west" : __DIR__"houting1",
	  "east" : __DIR__"menfang1",
	  "south" : __DIR__"banshichu",
	 "north" : __DIR__"gstart",
		]));
	set("objects", ([ /* sizeof() == 1 */
                  __DIR__"lin" : 1,
		]));

	setup();
}
