// Room: /open/hihi/shanlu2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"山路"NOR);
	set("long", @LONG
你沿着山路往上走。这里的山势比北面的要更为险恶。在这里爬山，还
是小心一点好。山路两旁的树木长得郁郁葱葱的，使你看不透。再往南就到
了青城山门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "northdown" : __DIR__"shanlu",
	  "southup" : __DIR__"shanmen",
		]));
	setup();
	replace_program(ROOM);
}
