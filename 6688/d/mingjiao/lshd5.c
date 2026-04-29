// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "山巅");
        set("long", @LONG
	山巅之上是好大一块平地，这里到处花木葱郁，彩蝶飞舞，实在是人间
仙境。西边又有一条小路蜿蜒而下，北面是一座小木屋。
LONG
	);
	set("exits", ([
	"west" : __DIR__"lshd6",
	"north": __DIR__"hall",
	"eastdown": __DIR__"lshd4",
	]) );
        setup();
        replace_program(ROOM);
}
