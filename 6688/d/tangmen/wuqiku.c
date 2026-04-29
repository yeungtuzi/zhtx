// wuqiku.c 武器库
// by tang

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是武器库，地下凌乱地放着几柄竹剑。一个锦衣中年人正在
整理，如果需要的话，可以向他要(yao)暗器、毒药和解药。
LONG
	);
	set("exits", ([
		"west" : __DIR__"lianwuchang",
	]));
	set("objects", ([
		"/obj/weapon/bamboo_sword.c": 2,
		CLASS_D("tangmen")+"/tanghong"	: 1,
	]));

	setup();
        	replace_program(ROOM);
}
