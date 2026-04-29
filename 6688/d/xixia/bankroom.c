// Room: /d/xixia/bankroom.c

inherit BANK;

void create()
{
	set("short", "董记钱庄");
	set("long", @LONG
这是中兴府最大的一家钱庄，整间屋子收拾得一尘不染。一
个四十出头的中年人坐在柜台后门，那中年人留着三绺长须，一副
精明干练的样子。钱庄里人络绎不绝，却是井然有序。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eastsquare",
]));
	set("objects", ([
		__DIR__"npc/dong": 1,
	]));

	setup();
}
