//chufang.c
//written by tang

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","厨房");
        	set("long", @LONG
       这里是唐门弟子吃饭的地方，收拾的相当整洁，旁边有一小灶，
正在做各种好吃的，有一个唐门六代弟子正在上菜。
LONG
        	);                                    
	set("no_fight",1);
	set("no_magic",1);

        	set("exits", ([
              		"north"  :__DIR__"ezoulang1",
        		]));                                          
	set("objects",([
		__DIR__"npc/dizi3"	: 1,
			]));
        	setup();
}


void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{
        	this_player()->start_busy(5);
        	write(YEL "你坐下来饱饱地大吃了一顿\n" NOR);
        	write(YEL "直吃得肚肥肠满才心满意足地站起身来\n" NOR);
		if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
		   return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");

		if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝的太多了，再也塞不下任何东西了。\n");
        	this_player()->set("food",this_player()->max_food_capacity());
        	this_player()->set("water",this_player()->max_water_capacity());
        	return 1;
}
