
inherit ROOM;

void create()
{
	set("short", "道法场");
	set("long", @LONG
	这是成都城内的一间道法场，由于多年战乱，来超度亡魂的人络绎
不绝，这间道法场的主持是一位神秘的人物，据说他精通茅山道术，和茅山
现任掌门有一些不为外人所知的纠葛。
LONG
	);

	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));

	set("objects", ([
		__DIR__"npc/taolord":1,
	]));

	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

