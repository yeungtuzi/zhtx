// /d/xizang/class/gold_wh/sroad1.c

inherit ROOM;

void create()
{
        set("short", "石板路");
        set("long", @LONG
这里是札什伦布寺中央广场南边的一条石板路,东边是道不太陡峭的山崖,西边
通往练武场,南边有座小屋是存放兵器用的.
LONG
        );
        set("exits", ([
		"north" : __DIR__"sroad",
		"south" : __DIR__"weapon",
		 "east" : __DIR__"cliff",
		 "west" : __DIR__"p_gnd",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
