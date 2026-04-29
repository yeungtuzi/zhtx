#include <ansi.h>

inherit ROOM;

void create()
{
			set("short","厨房");
        	set("long", @LONG
这里是华山派弟子吃饭的地方，收拾的相当整洁，旁边有一小灶，正在
做各种好吃的，有一个华山弟子正在做饭。
LONG
);                                    
			set("no_fight",1);
			set("no_magic",1);
        	set("exits", ([
              		"east"  :__DIR__"yuanzi",
        		]));                                          
			set("objects",([
				__DIR__"npc/dizi"	: 1,
				]));
        	setup();
}


void init()
{
        add_action("do_chifan", "chifan");

}

int do_chifan()
{			
			if(this_player()->query("family/family_name")!="华山派气宗")
				return notify_fail("你想吃白食啊。\n");
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
