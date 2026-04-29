// Room: /d/xixia/echufan.c

inherit ROOM;

void create()
{
	set("short", "御膳房");
	set("long", @LONG
御膳房到了，一定有不少山珍海味道吧，毕竟是皇宫嘛！你四周
仔细一看，全都是大块大块的牛肉、羊肉。原来西夏地处西北苦寒之
地，所食以牛羊为主，连皇宫也不例外。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad10",
]));
	set("objects", ([
		__DIR__"obj/leg": 1,
		__DIR__"npc/taijian": 2,
	]));

	setup();
	replace_program(ROOM);
}
