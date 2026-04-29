
inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
	这是一条宽阔的青石板街道，向东西两头延伸。街的南面是一座宅院，似已无人居住。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"guangchang",
		"west" : __DIR__"ximen",
		"south" : __DIR__"zhaiyuan",
	]));

        set("objects", ([
                "/d/village/npc/kid" : 2,
        ]));


	setup();
	replace_program(ROOM);
}

