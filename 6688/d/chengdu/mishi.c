
inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "密室");
	set("short", "密室");
	set("long", @LONG
     一间光线不足的小屋子，里面待着一个鬼鬼祟祟的家伙，大概是在想干什么坏事。
LONG
	);

	set("exits", ([
		"out" : __DIR__"xidajie1",
	]));

	set("objects", ([
		__DIR__"npc/yangxuyan":1,
	]));
	setup();
	replace_program(ROOM);
}
