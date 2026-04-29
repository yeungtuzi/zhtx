// Room: /d/xixia/southstreet2.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
一条由白石板铺成的宽阔街道，街道的西边尽头你看到了一座府
第，气派非凡，往南是城南的中心地带南门广场，往北通向皇宫。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"southstreet3",
  "south" : __DIR__"southsquare",
  "west" : __DIR__"generalgate",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/tubo1" : 1,
  __DIR__"npc/tubo2" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
