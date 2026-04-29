// Room: /d/xixia/barracks1.c

inherit ROOM;

void create()
{
	set("short", "中军都督府");
	set("long", @LONG
这里是中军都督府，专门负责中军的招募，训练，调动，作
战等事宜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad6",
]));

	set("objects", ([
		__DIR__"npc/knight": 3,
		__DIR__"npc/horse": 3,
	]));
	setup();
	replace_program(ROOM);
}
