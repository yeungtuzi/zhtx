//yongdao.c
inherit ROOM;

void create()
{
	set("short","甬道");
	set("long",
@LONG
进了濪灵门，是一条长长的甬道。这条甬道直通向西岳庙的主殿--濪灵殿，
两侧是郁郁葱葱的柏树和松树。松树和柏树都很高大，几乎把整条甬道的上空
到遮盖了起来，就象一顶大大的凉棚，再加上四周一阵阵微风吹来，直让人心
神欲醉。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yuetai",
		"south" : __DIR__"lingmen",
]));
		set("outdoors","huashan");
		setup();
		replace_program(ROOM);
}

