// /d/xizang/class/budala/newsroom.c

inherit ROOM;
// need to use standard newsroom setup
//inherit NEWSROOM;

void create()
{
        set("short", "邸报馆");
        set("long", @LONG
这里是拉萨驿附属的邸报馆,来自各地的官方文书,商旅快讯以及小道消息
都可以在这里交流.几名小贩穿梭来往于人群间,不时为各位客人奉上零食和茶
水,当然最后走时要收钱的
LONG
        );
        set("exits", ([
		"south" : __DIR__"station",
]));
	set("objects", ([
		__DIR__"npc/aby" : 1,
//		__DIR__"npc/oaks": 1,
	]));

	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	
        setup();
//        replace_program(ROOM);
}

//init to add sit, no quit, pay money
//valid_leave for pay
