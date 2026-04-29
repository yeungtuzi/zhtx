// Room: /d/lingjiu/xianchou.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一条平整的青石大道，路面皆是用长约七尺，宽约三尺的青
石铺成，实难以想象如此高峰之上居然还有如此浩大的工程！路
的两旁是茫茫松海。前面雾气蒸笼，看不甚远。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"entrance",
  "southdown" : __DIR__"xianchou",
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
