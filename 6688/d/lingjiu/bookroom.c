// Room: /d/lingjiu/bookroom.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是灵鹫宫的藏书室。书架上各种武学秘籍，应有尽有，
看来童姥在灵鹫宫里花了不少心血。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road2",
  "west" : __DIR__"medicineroom",
]));
	set("objects", ([
		__DIR__"npc/zhujian" : 1,
		__DIR__"obj/book1" : 1,
		__DIR__"obj/book2" : 1,
	]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if( (ob = present("zhu jian", environment(me))) && living(ob) && dir == "west" )
		return notify_fail("竹剑说道：“没有童姥的命令，谁也不许擅入药品房！”\n");
	return ::valid_leave(me, dir);
}
