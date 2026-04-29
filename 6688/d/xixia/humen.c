// Room: /d/xixia/humen.c

inherit ROOM;

void create()
{
	set("short", "虎门");
	set("long", @LONG
这里是虎门，一年一度的“秋审”和“朝审”就在这里举行，届时
全国各地被判死刑的囚犯被带到这里由刑部复审定案，不过大多难逃一
死，如入虎口，故曰虎门。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dadao" : 1,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"esquare",
]));

	setup();
	replace_program(ROOM);
}
