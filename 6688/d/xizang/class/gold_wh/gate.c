// /d/xizang/class/gold_wh/gate.c

inherit ROOM;

void create()
{
        set("short", "寺门");
        set("long", @LONG
这里是密宗金轮派札什伦布寺的大门.札什伦布寺也是依山势建成,气派不在
雪山寺之下,寺的西边新筑成的灵骨塔更是全藏边最高的一座,据说是法王为自己
修建的.
LONG
        );
        set("exits", ([
		"west" : __DIR__"fyard",
		"east" : __DIR__"uroad2",
]));

        setup();
	replace_program(ROOM);
}
