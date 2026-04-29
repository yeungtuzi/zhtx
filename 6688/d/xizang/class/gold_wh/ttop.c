// /d/xizang/class/gold_wh/ttop.c

inherit ROOM;

void create()
{
        set("short", "塔楼顶层");
        set("long", @LONG
这里是札什伦布寺新筑成的高塔顶层.塔楼内灯光昏暗,一尊尊镀金佛像在摇
曳的烛光下仿佛活动起来.
LONG
        );
        set("exits", ([
		"down" : __DIR__"t4",
]));
        setup();
	replace_program(ROOM);
}
