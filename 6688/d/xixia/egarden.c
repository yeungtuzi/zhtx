// Room: /d/xixia/egarden.c

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
走到这里，宫廷内凝重肃穆的气息尽去，换来的却是赏心悦目
的花草树木，千姿百态的水榭亭台。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/lifei" : 1,
  __DIR__"npc/pmaid" : 2,
]));
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eroad11",
  "south" : __DIR__"yroad1",
]));

	setup();
	replace_program(ROOM);
}
