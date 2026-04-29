
inherit ROOM;

void create()
{
	set("short", "康府花园");
	set("long", @LONG
这是一个小花园，现在还不是花儿盛开的季节，所以花儿不太多，
但环境十分幽雅清洁，显是平日有人修整打扫。看来是个清修的
好去处，再加上花园北边的佛堂，平增不少佛家气息。
LONG
	);
        set("outdoors", "city2");

	set("exits", ([
  		"east" : __DIR__"kang3",
  		"north" : __DIR__"fotang",
	]));
	setup();
	replace_program(ROOM);
}
