// /d/xizang/class/gold_wh/backdoor.c

inherit ROOM;

void create()
{
        set("short", "后门");
        set("long", @LONG
这里是札什伦布寺的后门,南边是寺的后院,北边门外是一条崎岖山路,好象通往
去昆仑山的方向.
LONG
        );
        set("exits", ([
		"north" : __DIR__"qqroad1",
		"south" : __DIR__"backyard",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
