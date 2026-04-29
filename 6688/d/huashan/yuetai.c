//yuetai
inherit ROOM;

void create()
{
	set("short","月台");
	set("long",
@LONG
走过了甬道，前面就是濪灵殿了。从外面看，濪灵殿是一座是琉璃瓦单檐
歇山顶式的建筑，面宽七间，进深五间，周有回廊，殿基高大，宏伟，整个殿
宇全部坐落在一个大月台上。月台呈凸字型，周围由大石条砌成，显得气势巍
然。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"northup" : __DIR__"lingdian1",
		"south" : __DIR__"lingmen",
]));
		set("outdoors","huashan");
		setup();
		replace_program(ROOM);
}

