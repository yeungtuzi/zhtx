// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "花叶居");
        set("long", @LONG
	这间小木屋内里陈设非常简单，并无其他特殊之处。实在不象名震江湖的
金花银叶的居所。银叶早已故去，金花婆婆坐在堂中，旁边侍立着一位青衣少女。
LONG
	);
	set("exits", ([
	"south" : __DIR__"lshd5",
	]) );

	set("objects", ([ /* sizeof() == 1 */
		 "/class/mingjiao/popo" : 1,
	]));

        setup();
        replace_program(ROOM);
}
