//daoroom1
//by emote
inherit ROOM;

void create()
{
	set("short","道士居室");
	set("long",
@LONG
这里是成年道士们起居的地方，但是现在这里没有人，道长们都在忙着
庙里面的各项事情，他们只有当晚上，或者做早课的时候才会到这里来聚集
起来。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"houyuan",
		
]));


	setup();
	replace_program(ROOM);
}

