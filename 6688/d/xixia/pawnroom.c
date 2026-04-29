// Room: /d/xixia/pawnroom.c

inherit HOCKSHOP;

void create()
{
	set("short", "丰登当铺");
	set("long", @LONG
这是一家中等规模的当铺，柜台上还可见到新木，显示
着这家当铺刚开业不久，柜台后面站着一个三十来岁的管家，
一脸奸笑。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eaststreet2",
]));
	set("objects", ([
		__DIR__"npc/dangpuguanjia": 1,
	]));

	setup();
}
