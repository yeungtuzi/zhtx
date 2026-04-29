// Room: /d/xixia/taimiao.c

inherit ROOM;

void create()
{
	set("short", "太庙");
	set("long", @LONG
这里是皇帝祭祀祖宗的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad7",
]));

	setup();
	replace_program(ROOM);
}
