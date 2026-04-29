// /d/xizang/house5.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这里是一座简陋的民宅,住着新近迁来的汉族石匠大雄和他的妻子儿女.
LONG
        );
        set("exits", ([
  "north" : __DIR__"octo7",
]));
        set("objects", ([
                __DIR__"npc/xiaoni" : 1,
		__DIR__"npc/gesang" : 1,
                __DIR__"npc/mami" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
