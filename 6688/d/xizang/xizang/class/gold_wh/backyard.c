// /d/xizang/class/gold_wh/backyard.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是札什伦布寺的后院.与前面宏伟的宫殿建筑群不同,这里更接近一般山野
的自然风光.东边是一大片菜园,种植着翠绿的蔬菜,西边是个小山坡,不远处有个黑
乎乎的洞口,下着铁栅栏门.不知道里面关着什么.北边是寺院的后门,通往一条崎岖
山路.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"garden",
		 "west" : __DIR__"slope",
		"north" : __DIR__"backdoor",
		"south" : __DIR__"backhall",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
