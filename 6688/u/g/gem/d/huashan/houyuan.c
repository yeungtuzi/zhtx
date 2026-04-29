//houyuan
inherit ROOM;

void create()
{
	set("short","后院");
	set("long",
@LONG
这是濪灵殿的后院，负责供奉香火的道人们都住在这里。比起濪灵殿里
面的喧哗，院子里静悄悄的，很是适合清修。北面的那一大间是西岳庙长老
所住的房间，东面的是成年道士们所住的，西面的则是小道士们住的地方。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"zhanglao_room",
		"west"  : __DIR__"daoroom1",
		"east"  : __DIR__"daoroom2",
		"south" : __DIR__"lingdian2",
]));


	set("outdoors","huashan");
	setup();
	replace_program(ROOM);
}

