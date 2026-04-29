// Room: /d/xixia/eroad11.c

inherit ROOM;

void create()
{
	set("short", "宫中小径");
	set("long", @LONG
这是一条清幽小径，与宫中其它小径不同，很少见人来往，走
上去却令人神清气爽。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eroad9",
  "west" : __DIR__"egarden",
]));

	setup();
	replace_program(ROOM);
}
