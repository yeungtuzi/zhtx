//ROOM: /d/hangzhou/xding.c
// by dwolf
//97.11.7

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "神像顶");
	set("long", @LONG
	  你来到神像顶，这儿非常窄，你不由担心会不会掉下去。让你高兴的
是这儿有一本书，还有一把枪插在地上，上书三个大字“岳王枪”(ywspear)，
不知道你能不能拔起来。这儿没有出路，你四处张望，忽然有个声音在空中响起
：要响出去，的发个誓言(swear)。
LONG
	);                   
	set("objects", ([
		__DIR__"npc/obj/wmbook2" : 1,
]));                   
	set("item_desc", ([
		"ywspear" : "枪由镔铁做成，沉重厚实，枪尖由玄铁做成，锋利\n"
"无比。似乎可以取起来。\n",
]));
	setup();
}                      

void init()
{
	add_action("do_pick", "pick");  
	add_action("do_swear", "swear");
} 
                                            
int do_pick(string arg)
{
        object me;
	object ob;
	me = this_player();
        
        if ( !arg || arg != "ywspear" )
                return notify_fail("你要拿什麽?\n");  
	
	if(query_temp("mark/been_get")) 
		return notify_fail("枪已被拿走了。\n");
                       
        if ( ((int)me->query_skill("unarmed") < 80) ) { 
                tell_object(me, "你臂力太低，拔不起来。\n");
                return 1;
        }

        else if( ((int)me->query("kee")<300))
             {tell_object(me, "你体力不太够喔！\n");  
              return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",50);
        message_vision("$N蹲下马步，提气在胸，想要拔起宝枪。\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N把枪拔了起来。 \n",me); 
		ob = new(__DIR__"npc/obj/ywsword");
                ob->move(me);   
		//me->set("marks/ywsword",1);
                set_temp("mark/been_get",1);
	     return(1);
        }
        return(1);
}        
                                     
int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return notify_fail("你要发什么誓言？\n");    

        if( arg=="爱国"
	||  arg=="热爱祖国") 
	{
		command("haha");
		tell_object(me, YEL"空中传来一阵大笑，：“好孩子，不愧是炎黄子孙。”\n"NOR, me);
		me->move("/d/hangzhou/hsting");
		tell_room(__DIR__"hsting", YEL"一人忽然从天而降。\n"NOR); 
		return 1;      
	}
}
                                                




