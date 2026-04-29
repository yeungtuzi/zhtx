
inherit ROOM;

void create()
{

	
        set("short", "小树林");
        set("long", @LONG
	一片幽静的小树林，到处开满了野花，蝴蝶随着你上下翻飞。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"hdg3",
  "north" : __DIR__"valley",
]));
        set("outdoors", "mingjiao");
        set("objects", ([
                __DIR__"npc/obj/wanghua" : 1,
        ]) );

        setup();
        //replace_program(ROOM);
	
}

void reset()
{
	object hua;
	if( objectp(hua = present("wanghua")) )
                new(__DIR__"obj/wangguo")->move(hua);
	::reset();	
}
