// /d/xizang/house1.c

inherit ROOM;

void create()
{
        object box, matter;
        set("short", "民居");
        set("long", @LONG
这里是一座简陋的民宅,住着一户穷苦的藏民.
LONG
        );
        set("exits", ([
  "east" : __DIR__"octo11",
]));
        set("objects", ([
                __DIR__"obj/trash" : 1,
                __DIR__"obj/junkblade" : 2,
                __DIR__"obj/junkstaff" : 1,
                "/obj/money/silver" : 1,
                __DIR__"npc/crazy_dog" : 2,
                __DIR__"npc/beggar" : 3,
                __DIR__"obj/junksword" : 1,
                __DIR__"obj/fake-tooth" : 1,
        ]) );
        setup();
        box = present("trash", this_object());
        matter = present("blade", this_object());
        matter->move(box);
        matter = present("staff", this_object());
        matter->move(box);
        matter = present("blade", this_object());
        matter->move(box);
        matter = present("silver", this_object());
        matter->move(box);
        matter = present("sword", this_object());
        matter->move(box);
        matter = present("tooth", this_object());
        matter->move(box);
}
