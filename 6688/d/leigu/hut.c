// Room: /d/leigu/hut.c

inherit ROOM;

void create()
{
	set("short", "农家小屋");
	set("long", @LONG
这是一间十分普通的农家小屋，屋内光线暗淡，一切看起来都是那么模糊，
进屋的右侧你似乎看到了一架织布机，屋的里侧则放着一些农具，似乎是
铁犁、锄头等！屋中间两人盘膝对坐。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"floor",
]));
	set("objects", ([
		__DIR__"npc/popo" : 1,
		__DIR__"npc/woman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
