// /d/xizang/class/bad/road4.c

inherit ROOM;

void create()
{
	set("short", "石板街转角");
	set("long", @LONG
青石板铺成的街道在这里转而向南,北边和东边各是一座石砌小屋,南边不远是
座高大的石屋,像是个祠堂.四外远处群山环抱,连绵不绝.
LONG
);
	set("exits", ([
		"north" : __DIR__"house3",
		"south" : __DIR__"road5",
		 "west" : __DIR__"road3",
		 "east" : __DIR__"house4",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
