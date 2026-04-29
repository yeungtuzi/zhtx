// /d/xizang/class/gold_wh/p_gnd.c

inherit ROOM;

void create()
{
        set("short", "小练武场");
        set("long", @LONG
这里是札什伦布寺的小练武场,法王的二弟子达尔巴通常在这里指点初级弟子
练武.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"sroad1",
		 "west" : __DIR__"p_hall",
]));
	set("outdoors", "xizang");
	set("objects", ([
		__DIR__"npc/daerba" : 1,
		__DIR__"npc/ddizi" : random(3),
	]));
        setup();
	replace_program(ROOM);
}
