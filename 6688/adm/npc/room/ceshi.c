// Room: /d/gumu/ceshi.c 
 
inherit ROOM;
#include <ansi.h>


int do_string(object me);
 
void create() 
{ 
        set("short", "古墓侧室");
        set("long", @LONG
       这里是古墓派侧室，四周都是石壁，异常的黑暗，一张寒玉床(bed)  
，还有一条细绳(string)悬在空中，好不怪异。 
LONG
        );
	set("no_fight", 1);        
	set("no_magic", 1);
        set("sleep_room", 1);
        set("max_sleeper",3);
        set("item_desc", ([ /* sizeof() == 2 */
  "bed" : "这是一块极地寒玉雕成的床，室内的阵阵寒意就是从床上发出的。 
不知你敢不敢在上面睡(sleep)\n",
  "string" : "一条纤细的绳子横悬在室内，难道是凉衣服用的不成？ 
",
]));
       
        set(
        	"exits", ([ /* sizeof() == 3 */
   		"south" : "/d/gumu/zoudao2.c",
	]));

        set("no_clean_up", 0);
        
 
    

}
void init()
{      
        add_action("do_sleep", "sleep");   
}

int do_sleep(string arg)
{
	object me;
        me = this_player();

	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成呢。\n");  

	if(me->query_condition("sleep"))
		return notify_fail("你刚在五分钟内睡过一觉, 多睡对身体有害无益! \n");

    	if (arg != "bed" )
    	{
    		if( arg == "string" ) return do_string(me); 
    	 	write("你要睡在哪里?\n"); 
    	 	return 1;
    	}    	
    	if(query("max_sleeper")<=0) {write("已经有人睡在这里了，你等一会儿吧!\n"); return 1;}
	if( (int)me->query_skill("yunu-xinfa",1)<40)
    	{
            write("你玉女心法不够。不能睡寒玉床\n");
	    return 1;
	}

	if( (int)me->query("max_force")<20)
    	{
            	write("你内力不够，睡寒玉床会伤身的。\n");
                return 1;
	}

	{
		message_vision("$N睡在寒玉床上，感到阵阵寒气传来，不得不运内力抵御. 渐渐地，$N睡着了。\n", me);
		me->set("no_get", 1);	
		me->set("no_get_from", 1);	
		me->set_temp("block_msg/all",1);
		me->disable_player("<睡梦中>");
		me->apply_condition("sleep", 25);
		call_out("end",random(45 - me->query("con")) + 1, me);
  		add("max_sleeper",-1);
 		return 1;	
 	}

}                     

void full_me(object me)
{
	int i;
	
	me->set("kee",  me->query("eff_kee"));
	me->set("gin",  me->query("eff_gin"));
        me->set("sen",  me->query("eff_sen"));
	if( (me->query("max_force")/2 - me->query("force")/2) > 0 )
		me->add("force", me->query("max_force")/2 - me->query("force")/2 );	
	if( (me->query("max_mana")/2 - me->query("mana")/2) > 0 )
		me->add("mana", me->query("max_mana")/2 - me->query("mana")/2 );	
	if( (me->query("max_atman")/2 - me->query("atman")/2) > 0 )
		me->add("atman", me->query("max_atman")/2 - me->query("atman")/2 );		

        /*  call move to re init all actions dao 971216 */
        {
        object * inv;

        me->move(__FILE__);
        inv = all_inventory(me);
                i = sizeof(inv);
                while(i--) {
                        string status=inv[i]->query("equipped") ;
                        inv[i]->move(me);
                        if( status == "worn" ) inv[i]->wear();
                }
        }
		
}	

void end(object me)
{
  	int i;

	i=2*((int)me->query("kee"));
    	me->set_temp("block_msg/all",0);
	me->enable_player();    	
	full_me(me);		
	me->add("kee",-((int)me->query("kee")/2));
 	me->add("force",i);
	message_vision("$N一觉醒来，舒舒服服的活动了一下筋骨.\n",me);
	message_vision("$N感到体内内力四方游动，在抵御寒气的过程中有所增强！\n",me);
 
	if ((int)me->query("force")>2*(int)me->query("max_force"))
	{
		if( me->query("max_force") < 1000 )
		{
			me->add("max_force",1);
			me->set("force",(int)me->query("max_force"));
	 		tell_object(me,HIW"你的内力增加了!!!\n"NOR);
	 	}
        	else
        	{                                                    
			me->set("force",(int)me->query("max_force")*2);        		
        	}	
 	}                                   
	add("max_sleeper",1);
	me->delete("no_get");	
	me->delete("no_get_from");	 
}


int do_string(object me)
{   	
    	if(query_temp("string_sleep")) {write("绳子上面已经有人了!\n"); return 1;}


	if(  me->query_dex() < 28 || me->query_skill_enabled("dodge")!="xianyun" )
    	{
	    message_vision("$N高高跃起，往绳子上面扑去，结果摔了个半死。\n",me);
	    me->unconcious();
	    return 1;
	}

	{
		message_vision("$N身形微动，轻轻巧巧地躺在了绳子上， 渐渐地，$N睡着了，睡梦中，居然还翻了个身。\n", me);
		me->set("no_get", 1);	
		me->set("no_get_from", 1);	
		me->set_temp("block_msg/all",1);
		me->apply_condition("sleep", 25);
		call_out("end1",random(45 - me->query("con")) + 1, me);
		me->disable_player("<睡梦中>");
		set_temp("string_sleep",me);
 		return 1;	
 	}

}                     

void end1(object me)
{
 	
	delete_temp("string_sleep");
    	me->set_temp("block_msg/all",0);
	me->enable_player();  
	full_me(me);	  	
	
	message_vision("$N一觉醒来，在绳子上翻了个身跳下地来，伸展了一下筋骨，舒服极了。\n",me);
	message_vision("$N感觉自己的轻功又有所进境！\n",me);

	if( me->query_skill("dodge") < 100 )
	{
		me->improve_skill("dodge",me->query_dex()*50);
	}	                                           	
	me->delete("no_get");	
	me->delete("no_get_from");	 
}
