inherit ROOM;

void create()
{
    set("short", "石路");
    set("long", @LONG
这是一条宽敞的大道，全由乱石堆成,显然曾花了不少人力。
LONG );

    set("exits", ([
	"south" : __DIR__"shidao2",
    ]));
    setup();
    replace_program(ROOM); 
}
