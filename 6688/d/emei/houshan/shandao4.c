// Room: /u/cuer/emei/shandao4.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里就
没有了，往西是来的路，往东正队着一个山洞，那山洞
就是著名的药王洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ywdong",
  "northwest" : __DIR__"shandao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
