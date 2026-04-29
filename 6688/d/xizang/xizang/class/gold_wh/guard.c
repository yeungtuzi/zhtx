// /d/xizang/class/gold_wh/guard.c

inherit ROOM;

void create()
{
        set("short", "守卫室");
        set("long", @LONG
这里是札什伦布寺守卫们休息的地方.法王尚武,武功修为全藏边可称最高,寺中
弟子也是人人习武,并选出一批武功较高者担职守卫,他们平时在寺内四处巡逻,累了
就在这里休息.
LONG
        );
        set("exits", ([
		"south" : __DIR__"fyard",
]));
	set("objects", ([
		__DIR__"npc/guard" : random(5),
	]));
        setup();
	replace_program(ROOM);
}
