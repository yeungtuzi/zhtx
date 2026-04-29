// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int carrying;

int conjure(object me, object target)
{
  object *inv;
      object ob;

	if( me->query_skill("essencemagic",1) < 20) 
		return notify_fail("你的八识神通不够，不能使用游识神通！\n");
        if (objectp(ob = present("shui jing",this_player()) ) )
                return notify_fail("你不能在挖宝的时候飞来飞去的，不怕找到的宝物被神仙收走了？\n");  
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用游识神通！\n");
	if( me->query("atman") < 75 )
		return notify_fail("你的灵力不够！\n");
        if( me->query("atman") < 75 )
                return notify_fail("你的灵力不够！\n");
        if( me->query("gin") <= 35 )
                return notify_fail("你的精不够！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用游识神通！\n"); 	
	if( target )
		return notify_fail("游识神通只能对自己使用！\n");
        inv = all_inventory(me);
        carrying = 0;

        if ( sizeof(inv) ){
           map_array(inv, "drop_npc");
           if ( carrying )
             return notify_fail("不能背着其他生物使用游识神通！\n");
        }
	write("你要移动到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void drop_npc(object ob)
{
  if ( ob->is_character() )
    carrying = 1;
}
    

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("中止施法。\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob) || environment(ob)->query("no_fly")
		|| environment(ob)->no_fly()) {
		write("你无法感受到这个人的灵力 ....\n");
		write("你要移动到哪一个人身边？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("战斗中无法使用游识神通！\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("你的灵力不够！\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N低头闭目，开始施展游识神通 ....\n" NOR, me);
	if( random(ob->query("max_atman")) < (int)me->query("atman") / 2 ) {
		write("你感受到对方的灵力，但是不够强烈。\n");
		return;
	}
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("你因为不够熟练而失败了。\n");
		return;
	}
        if(  userp(ob) ) {
                write("你不能施法飞向一个玩家。\n");
                return;
        }
        if( random(50) > 
	(int)(me->query_skill("essencemagic",1))){
                write("你因为不够熟练而失败了。\n");
                return;
        }                                                
        
        if( base_name(environment(ob))[0..8] == "/d/death/" || base_name(environment(me))[0..8] == "/d/death/")
        {
        	write("你只能在阳间和灵界穿行。\n");
        	return;
	}
	        	
	message( "vision", HIY "\n一道耀眼的光芒忽然罩住" + me->name() 
		+ "，几秒钟後，光芒和人一齐消失得无影无踪！\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n你的眼前突然出现一团耀眼的光芒，光芒中浮现出一个人影！\n\n" NOR,
		environment(ob), ({ me }) );
}

