// /d/xizang/class/budala/fhall.c

inherit ROOM;

void create()
{
        set("short", "前殿");
        set("long", @LONG
这里是布达拉宫前殿,两旁有甬道通往僧人诵经参禅的房间.
LONG
        );
        set("exits", ([
          "northup" : __DIR__"ustair1",
	"southdown" : __DIR__"fyard2",
	     "west" : __DIR__"wpath1",
	     "east" : __DIR__"epath1",
]));
//        set("objects", ([
//                __DIR__"npc/chashi" : 1,
//                ]));
        setup();
	set("valid_startroom",1);
}
