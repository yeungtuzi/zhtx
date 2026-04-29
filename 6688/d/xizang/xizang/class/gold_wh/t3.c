// /d/xizang/class/gold_wh/t3.c

inherit ROOM;

void create()
{
        set("short", "塔楼三层");
        set("long", @LONG
这里是札什伦布寺新筑成的高塔.塔楼内灯光昏暗,一尊尊镀金佛像在摇曳的
烛光下仿佛活动起来.
LONG
        );
        set("exits", ([
		"down" : __DIR__"t2",
		  "up" : __DIR__"t4",
]));
        setup();
	replace_program(ROOM);
}
