// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
	山路两侧树木葱翠，山林中不时有小鹿的身影闪过，一道山泉随山路潺潺而下。
LONG
	);
	set("exits", ([
	"westup" : __DIR__"lshd3",
	"east"	 : __DIR__"lshd1",
	]) );
        setup();
        replace_program(ROOM);
}
