//guangdie by tlang for saving duan yu

#include <ansi.h>
inherit ITEM;

int dest();

void create()
{
        set_name( HIM"光碟"NOR, ({ "guang die", "die" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", "金庸先生给段飞熊的一片光碟，不知道有什么用。\n");
                set("value", 500);
        }
 	set("unpawnable",1);	  
        setup();
}                                                    

void init()
{                            
//	add_action("do_use", "use");
}

int do_use(string arg)
{                 
	object ob = this_player();   
	object me = this_object();
	
        if( arg=="光碟"
	||  arg=="光盘") 
	{
		if( me->query("marks/been_used")<=3 )
		{
		message("vision", GRN"空中传来一阵刮来一阵仙风，把你带到了金庸身边！！\n"NOR, ob);
		ob->move("/d/suzhou/shuyuan");
		ob->start_busy(5);
		tell_room("/d/suzhou/shuyuan", YEL"$N被一阵仙风带来。\n"NOR,ob);      
		add("marks/been_used",1);
			return 1;
		}
		tell_object(ob,"一阵烟雾笼罩过来，之后光盘就不见了。\n");
		call_out("dest",1);
	        	return 1;      
	}
	return 0;
}                           

int dest()
{
	destruct(this_object());
	return 1;
}
                        
