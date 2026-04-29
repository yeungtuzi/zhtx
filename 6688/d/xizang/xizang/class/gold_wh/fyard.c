// /d/xizang/class/gold_wh/fyard.c

inherit ROOM;

void create()
{
        set("short", "前院");
        set("long", @LONG
这里是密宗金轮派札什伦布寺的前院,在这里可以更清楚地看见新筑成的高
塔.寺门在东边,北边是守卫休息的房间,南边是杂役的住处.
LONG
        );
        set("exits", ([
		 "west" : __DIR__"fhall",
		 "east" : __DIR__"gate",
		"north" : __DIR__"guard",
		"south" : __DIR__"misc",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
