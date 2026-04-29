// /d/xizang/octo7.c

inherit ROOM;

void create()
{
        object box, matter;
        set("short", "街道");
        set("long", @LONG
这里是拉萨城西南的街道,附近有很多民居.
LONG
        );
        set("exits", ([
   "east" : __DIR__"octo6",
  "north" : __DIR__"house3",
   "west" : __DIR__"house4",
  "south" : __DIR__"house5",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"npc/obj/trash" : 1,
                __DIR__"obj/junkblade" : 1,
                __DIR__"obj/junkstaff" : 1,
                __DIR__"obj/junksword" : 1,
        ]) );
        setup();
        box = present("trash", this_object());
        matter = present("blade", this_object());
        matter->move(box);
        matter = present("staff", this_object());
        matter->move(box);
        matter = present("sword", this_object());
        matter->move(box);
}
