// Room: /d/xixia/wuyingdian.c

inherit ROOM;

void create()
{
	set("short", "武英殿");
	set("long", @LONG
这里是皇帝与大臣商讨军国大事的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"taihemen",
]));

	setup();
	replace_program(ROOM);
}
