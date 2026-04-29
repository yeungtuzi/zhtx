// /d/xizang/octo12.c

inherit ROOM;

void create()
{
        object box, matter;
        set("short", "八角街");
        set("long", @LONG
这里是八角街的西北角,一条狭窄的街道往西延伸,附近有很多民房.街
道脏乱,到处是垃圾杂物.
LONG
        );
        set("exits", ([
  "east" : __DIR__"octo13",
  "west" : __DIR__"octo11",
 "south" : __DIR__"octo10",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"obj/trash" : 1,
                __DIR__"obj/junksword" : 1,
        ]) );
        setup();
        box = present("trash", this_object());
        matter = present("sword", this_object());
        matter->move(box);
}
