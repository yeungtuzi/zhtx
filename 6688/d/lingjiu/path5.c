// Room: /d/lingjiu/path5.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条非常精美的走廊，柱子是用的白玉石材料，上面盘旋
着几只尖嘴利喙的鹰鹫。走廊的地面上铺着红色地毯，走上去软软
的，非常舒服。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room9",
  "west" : __DIR__"path4",
  "south" : __DIR__"room8",
]));

	setup();
	replace_program(ROOM);
}
