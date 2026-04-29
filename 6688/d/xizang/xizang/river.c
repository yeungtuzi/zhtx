// /d/xizang/river.c

inherit ROOM;

void create()
{
        set("short", "雅鲁藏布江");
        set("long", @LONG
这里就是藏人常说的母亲河雅鲁藏布江,江水汹涌澎湃,两岸是葱绿的丛
林和草地,宛如人间仙境.
LONG
        );
        set("exits", ([
        "northup" : __DIR__"yvalley",
	  "south" : __DIR__"bridge",
]));
        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/somebody" : 1,
]) );
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
