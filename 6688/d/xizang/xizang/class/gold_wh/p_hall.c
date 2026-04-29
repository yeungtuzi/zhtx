// /d/xizang/class/gold_wh/p_hall.c

inherit ROOM;

void create()
{
        set("short", "演武厅");
        set("long", @LONG
这里是札什伦布寺的演武厅,法王有时会在这里考校亲传弟子的武功.平时这里
是金轮派弟子们互相切搓武艺的地方.大厅南边一间小屋内存放有金轮派武功秘籍,
西边是大练武场,东边是小练武场.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"p_gnd",
		 "west" : __DIR__"b_gnd",
		"south" : __DIR__"book",
]));
        setup();
	replace_program(ROOM);
}
