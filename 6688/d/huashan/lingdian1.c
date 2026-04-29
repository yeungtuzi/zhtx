//lingdian1
inherit ROOM;

void create()
{
	set("short","濪灵殿");
	set("long",
@LONG
进了濪灵殿，在你的正对面是一尊雄伟的神像，看来就是西岳的山神了。
这里就是古代历代帝王祭祀华岳的地方。四周的墙壁上悬挂着历代帝王封山
的诏书，还有帝王手迹。这些都是西岳庙的镇庙之宝，你可不能随便轻易把
它们拿下来看。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"lingdian2",
		"southdown" : __DIR__"yuetai",
		"west"  : __DIR__"lingdian3",
		"east"  : __DIR__"lingdian4",
]));
        set("objects", ([
                 __DIR__"npc/daoshi": 2,
		 __DIR__"npc/zhanglao":1, 
]));

	setup();
	replace_program(ROOM);
}

