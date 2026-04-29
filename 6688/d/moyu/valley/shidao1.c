inherit ROOM;

void create()
{
    set("short", "石路");
    set("long", @LONG
这是一条宽敞的大道，全由乱石堆成,显然曾花了不少人力。
LONG );

    set("exits", ([
    	"north"	    : __DIR__"shidao2",
    	"east"      : __DIR__"yizhan",
	"southeast" : __DIR__"in_valley",
    ]));
    setup();
    replace_program(ROOM); 
}
