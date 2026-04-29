// Room: /d/xixia/wumen.c

inherit ROOM;

void create()
{
	set("short", "午门");
	set("long", @LONG
这里是宫城的正门，建造得体型宏伟，在凹字形的城楼上，中间
建有庑殿顶的大殿，两旁有崇阁廊庑。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eroad8",
  "north" : __DIR__"eroad9",
]));

	set("objects", ([
		__DIR__"npc/shiwei6": 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
