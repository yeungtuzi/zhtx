// /d/xizang/class/bad/m_shop.c

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这里是一家药铺,卖的是毒药还是补药就没有人知道了,当然最大的可能是二者
兼而有之
LONG
);
	set("exits", ([
		"south" : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/emote" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
