// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "港口");
        set("long", @LONG
	这是海边一个小小的港口，现在只有一艘渔船停泊其中。
LONG
	);
	set("exits", ([
	"north" : "/d/qingcheng/bridge",
	"enter" : __DIR__"boat",
	]) );
        setup();
        replace_program(ROOM);
}
