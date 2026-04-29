// Room: /d/leigu/guli.c

inherit ROOM;

void create()
{
	set("short", "无名谷底");
	set("long", @LONG
你的眼前突然一亮，眼前竟是一个花团锦簇的翠谷，红花绿树，
交相掩映。柔软的草地上七八只野山羊在低头吃草，见了人也惊
避，树上十几只猴子跳跃相嘻。花香清幽，林鸟间关，鲜果悬枝，
想不到出了地道竟是一个洞天福地。放眼四望，但见翠谷四面雪峰
插云。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"didao3",
]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/supermaster" : 1,
		__DIR__"npc/laozhe1" : 1,
                __DIR__"npc/laozhe2" : 1,
	]));

	set("valid_startroom", 1);
	set("outdoors", "lingjiu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
