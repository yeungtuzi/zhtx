// Room: /d/xixia/barracks2.c

inherit ROOM;

void create()
{
	set("short", "左军都督府");
	set("long", @LONG
这里是左军都督府，专门负责左军的招募，训练，调动，作
战等事宜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad5",
]));

	setup();
	replace_program(ROOM);
}
