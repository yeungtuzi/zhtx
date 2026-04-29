// Room: /d/leigu/didao2.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
你在黑暗中摸索着，也不知走了多久，可是地道始终看不到尽头，
你心里不禁有些害怕起来，想转身往回走，奈何回去的路也已很
长，看来还是硬着头皮走下去吧！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"didao3",
  "east" : __DIR__"didao1",
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
	if( random(3) != 0 ){
		me->move(__FILE__);
		return notify_fail("");
	}
	return :: valid_leave(me, dir);
}
