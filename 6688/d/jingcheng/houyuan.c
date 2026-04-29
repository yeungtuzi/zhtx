//write by lysh
inherit ROOM;
void create()
{
        set("short", "赌场后厅");
        set("long", @LONG
这里是赌场后厅，中央有个赌桌，上面放着个碗，大管家坐在一旁。这后厅里
稀疏的呆着几个人。这些客人一看就不是善类，一个个目光如电，手法轻巧，都是
赌场老手。但他们对做在一旁的大管家都毕恭毕敬。据说大管家赌技深不可测，而
且他不和人赌钱，只和人赌命，赢了他的人，就可以到赌场的后院去，那里到底有
什么，江湖上没人知道。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ytgj",
 
]));
        set("objects", ([
        "/adm/npc/daguanjia" : 1,
        __DIR__"obj/wan":1,
                        ]) );
	set("no_faint",1);
        setup();
}


void reset()
{
       object *inv;
       object con, item;
       ::reset();
       con = present("wan", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
       item = new(__DIR__"obj/shaizi");
       item->set_amount(3);
       item->move(con);
       }
}
