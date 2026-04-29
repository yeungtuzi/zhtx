// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
	岛东边的山路与西边完全不同，这里全是光秃秃的山石。四下里十分的荒凉。
LONG
	);
	set("exits", ([
	"east" : __DIR__"lshd5",
	"north": __DIR__"lshd7",
	]) );
        setup();
        replace_program(ROOM);
}
