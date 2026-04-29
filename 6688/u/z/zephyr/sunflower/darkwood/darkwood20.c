//darkwood20.c
//by zephyr
//葵花宫秘密入口

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

int do_dig(string arg);
int do_say(string);
object *all;

string look_tree();

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG

这里仿佛已经到了森林的尽头。再往前就找不到路了。这里已经完全见不到天空了。
四处全是黑压压的一片，你什么都看不见.......
...........
..................
..........................
.....................................

停留了半晌，你开始渐渐适应周围的黑暗，靠着从树木缝隙里折射下来的微弱光线，
睁大了眼睛四处仔细查看：四周全是参天古树，仿佛几千年没有人来过这个地方了。
除了来路，这里找不到任何的出路。
不知道怎么的，你总觉得周围有什么不太对劲的地方。这里好像阴气森森，你不由得
寒毛直竖起来：直觉告诉你还是赶紧离开这里吧！


LONG NOR);

	set("item_desc", ([
        "古树" : (: look_tree :),
        "big tree" : (: look_tree :),
		]));


	set("objects", ([
		__DIR__"npc/anyeyouling.c" : 1,
	
	]));


	set("exits", ([
		"northeast" : __DIR__"darkwood18",
	])); 

	
	setup();

}


void init()
{       
        add_action("do_dig","dig");
        add_action("do_break","break");
        add_action("do_touch", "touch");
}

int do_dig(string arg)
{
	object me=this_player();
	int break_damage;
	
	all=all_inventory(environment(me));
	for(int i=0;i<sizeof(all);i++)
	{
		if((all[i]->query("id")=="you ling"))
			return 0;
	}


	all=all_inventory(environment(me));
	for(int i=0;i<sizeof(all);i++)
	{
		if((all[i]->query("id")=="you ling"))
			return 0;
	}

	if(!me->query_temp("tent_2")) return 0;

    if ((arg !="地面" || !arg))
        return notify_fail("\n你想干吗？\n");
    if ((int)me->query("force") < 5000 ) { 
		   	message_vision(CYN"\n$N蹲下身子在那棵古树脚下用力的挖起来.........\n"NOR + CYN"虽然那里的土质虽不是很硬，但是由于那古树树根盘根错节，紧紧抓着土壤，\n"NOR + CYN"十分坚固，$N挖了半天只挖起了点地皮。\n"NOR,me);
    } 
    else 
    {
			message_vision(CYN"\n$N在那棵古树脚下蹲下身子，暗运一口气，力灌指尖，以手为铲，使劲挖起来。\n"NOR + CYN"不一会，$N就满头大汗，可是那块地面也渐渐的被挖出了一个大洞出来，\n\n" NOR+ BLU"忽然，$N大叫一声”啊哟！痛死我也！“原来$N的手指一下抓在了一块岩石上！\n\n"NOR + "( $N" + HIY"受伤不轻，看起来状况并不太好。 "NOR + ")\n\n" + CYN"$N强忍剧痛，趴下身子用力去推了推那块岩石，竟发现它好似微微摇晃，$N双手\n"NOR + CYN"出力狠推，摇晃之感更甚，岩石既然埋于土中，按理决计推之不动。$N伸手到岩\n"NOR + CYN"石周围摸了一遭，原来此岩表面居然刻有花纹显然并非天生。$N心中怦的一跳：\n\n\n"NOR + HIR"		“这里有古怪！”，\n\n\n"NOR,me); 
			break_damage = random(500);
			me->receive_wound("kee",break_damage);
			me->set_temp("dwd_1",1);
    } 
    return 1;

}

int do_break(string arg)
{
    object me = this_player();
	int break_damage;
	if(!me->query("darkwood_tunnel")) 	
	{
		all=all_inventory(environment(me));
		for(int i=0;i<sizeof(all);i++)
		{
			if((all[i]->query("id")=="you ling"))
			return 0;
		}

		if(!me->query_temp("tent_2")) return 0;
	
		if(!me->query_temp("dwd_1")) return 0;
	
		if ((arg !="岩石" || !arg))
			return notify_fail("\n你想干吗？\n");
			if ((int)me->query("force") < 3000 ) { 
			message_vision(CYN"\n$N奋起内力一掌向那块岩石拍去！只听$N闷哼一声\n\n\n"NOR + "( $N" + HIY"受伤不轻，看起来状况并不太好。 "NOR + ")\n\n" + CYN"可那岩石剧烈的晃了几下就再没什么动静了。\n\n"NOR,me);
			break_damage = random(500);
			me->receive_wound("kee",break_damage);
		} 
		else 
		{
			message_vision(CYN"\n$N盘膝而坐，吐呐良久.....\n\n"NOR + YEL"忽然$N大吼一声，内力凝于双掌猛力向岩石推去！\n\n"NOR + CYN"只听到轰的一声巨响！！！一时间古树和周围的地面都震动起来\n\n"NOR + "( $N" + HIY"受伤不轻，看起来状况并不太好。 "NOR + ")\n\n" + CYN"岩石轰隆隆滚落下去，$N也已经禁受不起，哇的吐出一大口鲜血，\n"NOR+ CYN"踉跄了一下，一跤跌进洞里。\n\n"NOR + CYN"接着周围的土块瓦砾也跟着落了进去，把洞口堵住了。\n\n\n"NOR,me); 
			break_damage = random(1000);
			me->receive_wound("kee",break_damage);
			me->set("darkwood_tunnel",1);
			me->move("/u/z/zephyr/sunflower/tunnel/tunnelentrance"); 
			message("vision",CYN"\n只听到上面传来轰隆隆几声闷响，过了一会，一块岩石滚了下来！！！\n"NOR+CYN"地道如此狭窄，你拼命的左闪右躲，险些被石块打中。" +  "只见"+ me->query("name") + CYN"扑嗵摔\n"NOR + CYN"在你身边，险些砸到你\n"NOR, environment(me), me);

		} 
		return 1;
	}
	else 
	{
		message_vision(CYN"\n$N盘膝而坐，吐呐良久.....\n\n"NOR + YEL"$N凝神闭目，内力凝于双掌缓缓向岩石推去！\n\n"NOR + CYN"只听到吱嘎嘎几声巨响，一时间古树和周围的地面都震动起来\n\n"NOR + "( $N" + HIG"似乎有些疲惫，但是仍然十分有活力。  "NOR + ")\n\n" + CYN"岩石轰隆隆滚落下去，$N轻轻一跃，跳进洞里。\n\n"NOR + CYN"接着周围的土块瓦砾也跟着落了进去，把洞口堵住了。\n\n\n"NOR,me); 
		break_damage = random(2);
		me->receive_wound("kee",break_damage);
		me->move("/u/z/zephyr/sunflower/tunnel/tunnelentrance"); 
		message("vision",CYN"\n只听到上面传来轰隆隆几声闷响，过了一会，一块岩石滚了下来！！！\n"NOR+CYN"地道如此狭窄，你拼命的左闪右躲，险些被石块打中。" +  "只见"+ me->query("name") + CYN"轻轻\n"NOR + CYN"稳稳地落在你的身边。\n"NOR, environment(me), me);
		return 1;
	}

}


string look_tree()
{
	object me=this_player();
	all=all_inventory(environment(me));
	for(int i=0;i<sizeof(all);i++)
	{
		if((all[i]->query("id")=="you ling"))
			return 0;
	}
	me->set_temp("tent_1",1);
	return "\n你定睛看去……良久。可是周围依旧是漆黑一片，什么都看不到\n\n";
}


int do_touch(string arg)
{
	object me=this_player();
	
	if( !arg || arg=="" ) return 0;

	if( arg=="古树脚下的地面"
	||  arg=="古树脚下的地"
	||  arg=="树根边的地面"
	||  arg=="树根旁边的地面"
	||  arg=="古树根边的地面"
	||  arg=="古树根旁边的地面") 
	{	
	all=all_inventory(environment(me));
	for(int i=0;i<sizeof(all);i++)
	{
		if((all[i]->query("id")=="you ling"))
			return 0;
	}

		if(me->query_temp("tent_1") )
		{
			if ( random (100) >5) {
				message_vision(CYN"$N慢慢的挪到一棵大树旁边仔细摸着树根旁边的地面……良久。但是一无所获\n", me);
			}
			else {
				message_vision(YEL"$N慢慢的挪到一棵巨大无朋的大树旁边仔细摸索着..............\n", me);
				tell_object(me,HIW"\n忽然你灵光一闪：怎么这块地的土壤居然是干燥的呢？？？一定有蹊跷！\n"NOR);
				me->set_temp("tent_2",1);
			}
			return 1;
		}
		else return 0;
	}
}
