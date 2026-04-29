// /d/xizang/class/gold_wh/path.c

inherit ROOM;

void create()
{
        set("short", "甬道");
        set("long", @LONG
这里是前门殿后的甬道,全部由小块花岗岩铺成.西边就是札什伦布寺的中央
大殿,从这里往西可以走到殿前广场.北边是大殿的东厢房,供朝拜的香客休息,南
边是讲经房.法王不喜讲经,通常都是委托一名弟子在那里代为宣讲.
LONG
        );
        set("exits", ([
		 "east" : __DIR__"fhall",
		 "west" : __DIR__"cyard",
		"north" : __DIR__"east",
		"south" : __DIR__"lecture",
]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
