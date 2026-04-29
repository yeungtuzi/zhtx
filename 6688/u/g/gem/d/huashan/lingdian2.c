//lingdian2
inherit ROOM;

void create()
{
	set("short","后殿");
	set("long",
@LONG
这里是濪灵殿的后殿，这里供奉着三清的塑像，正中间的是道教的主神
原始天尊，左边是太上老君，右边则是灵宝道君。比起前殿来这里就清静的
多，这里只有几个扫地道士在这里负责打扫，连香炉里面也都只有按惯例上
的香，比不上前殿的供奉。再往前走，就是道士们住的后院了。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"lingdian1",
		"north" : __DIR__"houyuan",
]));
        set("objects", ([
                 __DIR__"npc/daoshi2": 2,
]));

	setup();
	replace_program(ROOM);
}

