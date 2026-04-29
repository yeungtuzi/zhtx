// Room: /class/qingcheng/bridge.c

inherit ROOM;

void create()
{
	set("short", "[33m石桥[2;37;0m");
	set("long", @LONG
石桥已经很古老了，单从那不知道被人们婆娑了多少次的石栏杆，就可
以看出这点。河水从桥下潺潺流过，那水声听在心头，有说不出的舒服。平
时如果有空，到这里游山玩水可真不错。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"nankou1",
		"north" : __DIR__"port",
                "south" : "/d/mingjiao/gangkou",
]));

	setup();
	replace_program(ROOM);
}
