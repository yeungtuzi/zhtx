// /d/xizang/xmly4.c

inherit ROOM;

void create()
{
        set("short", "开阔地");
        set("long", @LONG
这里是一片林中的开阔地,似乎适合宿营.东北边是下山的方向,西边是上山的
方向,南边有座小木屋.
LONG
        );
        set("exits", ([
        "northeast" : __DIR__"xmly3",
	   "westup" : __DIR__"xmly5",
	    "south" : __DIR__"w_house",
]));
//	set("objects", ([
//		__DIR__"npc/bird" : random(3),
//	]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
