// /d/xizang/class/budala/easthall.c

inherit ROOM;

void create()
{
        set("short", "东殿");
	set("long", @LONG
这里是布达拉宫东殿,本来是为藏边的另外三位佛法高深的僧人保留,但他们现
在都不大肯来此讲经说法.
LONG
        );
        set("exits", ([
          "east" : __DIR__"boy",
	 "south" : __DIR__"lamp2",
]));
//        set("objects", ([
//                __DIR__"npc/danma",
//]));
        setup();
        replace_program(ROOM);
}
