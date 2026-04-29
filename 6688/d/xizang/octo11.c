// /d/xizang/octo11.c

inherit ROOM;

void create()
{
 	object box,matter;
 	
        set("short", "街道");
        set("long", @LONG
这里是拉萨城西的街道,周围是许多的民房.
LONG
        );
        set("exits", ([
  "east" : __DIR__"octo12",
  "west" : __DIR__"house1",
  "south" : __DIR__"house2",
]));
        set("outdoors", "xizang");
        set("objects", ([
                __DIR__"obj/trash" : 1,
                __DIR__"obj/junkstaff" : 1,
        ]) );
        setup();
        box = present("trash", this_object());
        matter = present("staff", this_object());
        if( objectp(box) && objectp(matter) )
        	matter->move(box);
}
