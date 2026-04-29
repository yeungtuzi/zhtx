// Room: /d/lingjiu/xianchou.c

inherit ROOM;

void create()
{
	set("short", "仙愁岭");
	set("long", @LONG
这里就是仙愁岭了，据说仙人也难以走到这里来，因而得名。这里
已经离缥缈峰顶已经不远了，白雪皑皑的地上挺起无数的青松，中
间铺着一条青石板路，没在松林里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"qingshilu",
  "south" : __DIR__"chain",
]));
	set("objects", ([
		__DIR__"npc/yu" : 1,
		__DIR__"npc/dizi1" : 2,
]));
	set("outdoors", "lingjiu");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
