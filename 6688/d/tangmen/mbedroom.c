// Room: /d/tangmen/mdedroom.c         
//writen by tang

inherit ROOM;

void create()
{
       	set("short", "男弟子休息室");
       	set("long", @LONG
这里是唐门男弟子休息的地方。靠墙一溜摆着几张木床，床
上铺的是棉被。使人一看就想睡觉。
LONG
        		);
       	set("exits", ([ /* sizeof() == 1*/
  		"south"  : __DIR__"wzoulang1",  
		]));
	set("sleep_room",1);
	set("no_fight",1);
	set("no_magic",1);

       	setup();
       	replace_program(ROOM);
}

