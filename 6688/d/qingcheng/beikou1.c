// Room: /open/hihi/beikou1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"北口"NOR);
	set("long", @LONG
  你来到了福州的北边，路的两边的农家渐渐多了，也多了许多匆匆忙忙
的路人，他们正在为一天三餐而劳碌。在往南就要进入福州城了，北面是一个
小亭。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
	  "south" : __DIR__"beimen",
          "north" : __DIR__"ssroad",
		]));
     //暂时把海公公放在这里
     set("objects",([
       __DIR__"npc/hai":1,
        ]));
	set("outdoor","qinglong");
	setup();
	replace_program(ROOM);
}
