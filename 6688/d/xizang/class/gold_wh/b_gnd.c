// /d/xizang/class/gold_wh/b_gnd.c

inherit ROOM;

void create()
{
        set("short", "大练武场");
        set("long", @LONG
这里是札什伦布寺的大练武场,法王的大弟子桑吉多通常在这里指点初级弟子
练武.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"p_hall",
	      "northup" : __DIR__"grass",
]));
	set("outdoors", "xizang");
	set("objects", ([
		__DIR__"npc/sangjd" : 1,
		__DIR__"npc/dizi" : random(5),
	]));
        setup();
	replace_program(ROOM);
}
