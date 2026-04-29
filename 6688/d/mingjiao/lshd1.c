// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "山脚");
        set("long", @LONG
	这里山石直降入海，并无浅滩，海船吃水虽深，却仍可泊在岸边。
LONG
	);
	set("exits", ([
	"west" : __DIR__"lshd2",
	"enter" : __DIR__"boat1",
	]) );
        setup();
        replace_program(ROOM);
}

