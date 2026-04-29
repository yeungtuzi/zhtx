//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"小秦淮酒家三楼"NOR);
	set("long", @LONG
这是一家充满着异域情调的酒馆。这里不但供应本地的各种
名酒，你也可以买到来自西域或南洋的各种美酒。李白，贺
知章都是这里的常客。现在只有一个客人。
LONG         
	);   
	set("objects", ([
		"/class/tieflag/yunjiuxiao.c" : 1,
]));

	set("exits", ([ 
	  "down" : __DIR__"jiuguan2.c", 
 	]));

	set("sleep_room",1);
	set("family","铁血大旗门");
        set("no_faint",1);
	set("no_fight",1);
	set("no_poison",1);
	set("no_magic",1);
	setup();
}

int no_fly()
{
	return 1;
}

void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
	write("这里光线不适合读书.\n");
	return 1;
}

#include "/std/room/check_room_family.c"


