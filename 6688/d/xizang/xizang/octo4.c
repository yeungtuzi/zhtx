// /d/xizang/octo4.c

inherit ROOM;

void create()
{
        set("short", "八角街");
        set("long", @LONG
这里是大招寺外的街道,一些喇嘛香客来来往往.
LONG
        );
        set("exits", ([
  "west" : __DIR__"octo5",
  "east" : __DIR__"octo3",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"npc/lama2" : 2,
		NPC_DIR"traveller" : random(3),
        ]) );
        setup();
        replace_program(ROOM);
}
