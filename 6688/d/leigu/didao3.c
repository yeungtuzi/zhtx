// Room: /d/leigu/didao3.c

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
你的眼前似乎有一些微光，看来已经接近地道的出口，你不禁有些
兴奋，心想终于到头了，可是无论你走啊走，那光始终是那么微弱，
你的心情越来越沮丧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guli",
  "east" : __DIR__"didao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
