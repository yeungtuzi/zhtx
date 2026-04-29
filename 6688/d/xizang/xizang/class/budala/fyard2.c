// /d/xizang/class/budala/fyard2.c

inherit ROOM;

void create()
{
        set("short", "前院");
        set("long", @LONG
这里是布达拉宫的前院,两边是饭厅和茶室.僧人和香客可以在这里免
费进食饮水.
LONG
        );
        set("exits", ([
          "south" : __DIR__"fyard1",
        "northup" : __DIR__"fhall",
           "east" : __DIR__"drink",
           "west" : __DIR__"eat",
]));
        set("outdoors", "xizang");
	set("objects", ([
		__DIR__"npc/b_lama" : 1+random(6),
		__DIR__"npc/xiangke": 1+random(4),
	]));
        setup();
        replace_program(ROOM);
}
