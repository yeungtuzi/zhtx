
inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "散花楼");
	set("short", "散花楼二楼");
	set("long", @LONG
     这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃喝边
作交易。这里也是城里举办喜宴的最佳场所。墙上挂着价格牌子(paizi)。你站在楼
上眺望蓉城，只觉得心旷神怡。
LONG
	);

	set("item_desc", ([
		"paizi" : "本店经营正宗川菜。\n",
	]));

	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));

	set("objects", ([
		__DIR__"npc/cheng":1,
	]));
	setup();
	replace_program(ROOM);
}
