// /d/xizang/class/gold_wh/chall.c

inherit ROOM;

void create()
{
        set("short", "中央大殿");
        set("long", @LONG
这里是札什伦布寺的中央大殿.殿宇高大,气象恢宏.描金画彩的佛像宝相庄
严,前来上香朝拜的香客络绎不绝.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"east",
		 "west" : __DIR__"west",
		"south" : __DIR__"cyard",
		"north" : __DIR__"pathn",
]));
	set("objects", ([
		__DIR__"npc/fawang" : 1,
	]));
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
