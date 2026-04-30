// /d/xizang/octo6.c

inherit ROOM;

void create()
{
        // 2026-04-30: unused variable commented out
        // object box, matter;
        set("short", "八角街");
        set("long", @LONG
城市赤如皮革，有光滑美丽的一面，也有粗糙丑陋的一面。这段八角街
上垃圾粪便狼藉。成群结队的年老乞丐，穿着破旧褴褛的衣服，剃光头打赤
足，匍匐在尘土中，等待着行人香客的施舍。
LONG
        );
        set("exits", ([
   "north" : __DIR__"octo8",
   "east" : __DIR__"octo5",
   "west" : __DIR__"octo7",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"npc/obj/trash" : 1,
                "/obj/money/silver" : 1,
                __DIR__"npc/scavenger" : 1,
                __DIR__"npc/dog" : 2,
                __DIR__"npc/woodcutter" : 1,
        ]) );
        setup();
}
