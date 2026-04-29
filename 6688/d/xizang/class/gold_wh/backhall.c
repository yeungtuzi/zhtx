// /d/xizang/class/gold_wh/backhall.c

inherit ROOM;

void create()
{
        set("short", "后殿");
        set("long", @LONG
这里是札什伦布寺的后殿,是法王休息的地方.相对于中央大殿,它显得简朴
多了,但是仍然装饰得十分华丽.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"backe",
		 "west" : __DIR__"backw",
		"south" : __DIR__"pathn",
		"north" : __DIR__"backyard",
]));
	setup();
	replace_program(ROOM);
}
