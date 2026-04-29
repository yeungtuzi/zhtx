
inherit ROOM;
#include "/std/room/check_room_family.c"


void create()
{
        set("short", "练功室");
        set("long", @LONG
干干净净的墙上挂着一幅字画，上面写到“知山有路勤为径，
学海无涯苦作舟。”地上打扫的一尘不染，墙角堆着很多竹刀剑。
有些弟子正坐在地上休息.
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"back_yard",
]));
        set("sleep_room",1);
	set("no_faint",1);
	set("family","铁雪山庄");

       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
                __DIR__"obj/pieces" : 3,
        ]) );

        set("no_fight", 1);
        set("sleep_room", 1);
        set("no_magic", 1);
        setup();
}

void init()
{
	add_action("do_gets", "get");
}

int do_gets(string arg)
{
	if(arg == "all")
	{
		write("你太贪心了。\n");
		return 1;	
	}
	else
		return 0;
}
