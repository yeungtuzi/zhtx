// Room: /u/p/pock/bj/aobai1.c

inherit ROOM;

void create()
{
	set("short", "[36m十里长街[2;37;0m");
	set("long", @LONG
再往西就是鳌拜府了，因为鳌拜一介武夫，只会行军打仗，又凭借其手 
中的兵权，所以也没有把谁看在眼内，跟京城的其它亲王和文武百官都没有 
什么来往。而这里也显得冷清多了。 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bing" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"xidan",
		"east" : __DIR__"changjie1",
		"west" : __DIR__"aobai2",
]));

	setup();
	replace_program(ROOM);
}
