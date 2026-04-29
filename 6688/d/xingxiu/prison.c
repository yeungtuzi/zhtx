// Room: /d/xingxiu/prison.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这是一个很小的山洞，与外面阴冷潮湿的环境相比，这里相对来说干燥多了，也不容易
受各种毒虫的干扰。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"road3",
]));
	set("objects", ([
		__DIR__"npc/prisoner" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
