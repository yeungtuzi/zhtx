// /d/xizang/inn2.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "丹青小屋");
        set("long", @LONG
这里是迎梅客栈南边的一座小屋,四壁挂满了画轴(pictures),店主铁笑
就住在这里.
LONG
        );

        set("item_desc", ([
          "pitures": "你看了一会儿,发现所有的画上人物都是同一个女孩子\n",
        ]) );

        set("exits", ([
		"north": __DIR__"inn",
                ]) );
        set("objects", ([
                __DIR__"npc/tiexiao" : 1 ]) );
        setup();
	replace_program(ROOM);
}
