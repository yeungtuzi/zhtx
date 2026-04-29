// Room: /d/xixia/neitang.c

inherit ROOM;

void create()
{
	set("short", "青凤阁内堂");
	set("long", @LONG
这里是青风阁内堂，外面就是凝香堂，西边你看到了一条长
长的甬道，不知尽头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ypath1",
  "east" : __DIR__"qingfengge",
]));

	setup();
	replace_program(ROOM);
}
