// Room: /d/leigu/path0.c

inherit ROOM;

void create()
{
	set("short", "擂鼓山脚");
	set("long", @LONG
从此往东盘旋而上可达擂鼓山顶。当年岳飞攻金时，曾在此布下疑
阵，金兵听到漫山遍野的鼓声和助威声，以为宋兵大军到达，不敢
前进，因而得名。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path1",
  "northeast" : "/d/road/luoyang",  
]));
	set("no_clean_up", 0);
	set("outdoors", "leigu");

	setup();
	replace_program(ROOM);
}
