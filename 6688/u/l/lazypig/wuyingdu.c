// tm_poison.c

inherit COMBINED_ITEM;

void create()
{

        set_name("无影毒", ({ "wuying du", "du" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "这是唐门极利害的无影毒.\n" );
                set("unit", "包");
                set("base_value", 100);
                set("base_unit", "包");
                set("base_weight", 10);
        }
	set_amount(50);
}

void init()
{
	add_action("do_poison","poison");
}

int do_poison(string arg)
{   
	object me,you;
	int i,j,level;          
	string name,skill;
	int pp,dp;

	me=this_player();

	if( environment(me)->query("no_poison") || environment(me)->query("sleep_room"))
		return notify_fail("不许在这下毒!\n");
	
	if( !arg)	return notify_fail("你要给谁下毒?\n");

	if( arg==(string)this_player()->query("id") )
		return notify_fail("不许服毒自杀!\n");
                      
	you = present(arg, environment(this_player()));

	if( !objectp(you) )
		return notify_fail("这里没有这个人。\n");           
	if( !you->is_character() || you->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
                                   
	name=you->query("name");

	if( me->is_busy() )	return notify_fail("你正在忙别的，腾不出手来下毒。\n");

	if ( !query_amount() )	return notify_fail("你已经没有毒药可下。\n"); 

	skill=me->query_skill_mapped("force");

	if( skill != "tangmen-xinfa" && skill != "sunv-xinfa")
		return notify_fail("你的内功不对，不能下毒。\n");
	
	if( me->query_skill(skill,1) < 20 )
		return notify_fail("你的内功级别不够，下毒会伤着自己。\n");

	if( me->query_skill("dugong",1) < 40 )
		return notify_fail("你的毒功级别不够，下毒手段还不够高。\n");

	// 防止采用这个pk,只对和自己战斗中的玩家有效 yeung
	if( userp(you) && !me->is_fighting(you) ) 
		return notify_fail("你不可以在这种情况下对玩家下毒。\n");
	
	me->receive_damage("sen",10);
	me->start_busy(1);
/*
	i=me->query("int")+me->query_skill("literate",1)/10+me->query("cps")/3+me->query("spi")/3;
	i+=me->query_skill("dugong",1)/30;

	j=you->query("int")+you->query_skill("literate",1)/10+you->query("cps")/3+you->query("spi")/3;
	j+=you->query_skill("dugong",1)/30;
*/
	add_amount(-1);

	if( you->query("age")<=15 ) return notify_fail("对小孩子你也下毒，太没有人性啦。\n"); 
/*
	if( !userp(you) && !inherits(F_MASTER,you) ) j /= 2;
	if( i>j )
	{
		//这个算法未免成功率也太高了       yeung
//		if( random(i-j)!=0 )
		 //稍微低点,不过还是比普通的算法高 (相同天赋和literate的到头，大概 random(428)>107 的概率,75%,原来会有7/8的概率)
		if( random(i*4+j) > j )
		{
			level=me->query_skill("dugong",1);
			you->add("kee",-(level+random(level))/4);
			you->apply_condition("tm_poison", random(level)/10 + 1 
				+ you->query_condition("tm_poison"));

			tell_object(me,"你成功地在"+name+"身上下毒。\n");
			return 1;
		}
	}
*/
	//我认为原来的算法只比天赋实在是不合理,一个行走江湖多年经验丰富的人
	//会被一个新手毒死?而且不是因为别的,只是因为自己的灵性和悟性不如别人高?
	//算法中毒功的作用反而不大					yeung
	//这个算法主要看毒功的等级
	level = me->query_skill("dugong",1); //220max
	level += me->query("int"); //220+59max
	pp = level*level/2*level; //580万
	//对方的防毒能力看经验和其自身的毒功
	level = you->query_skill("dugong",1); //220max
    pp += me->query("combat_exp");
	dp = you->query("combat_exp");//368万max
    if (dp > 30000000) dp = 30000000; //3000w max
	dp += level*level/4*level; //266万max
	//如果是自己唐门的人dugong 220,很难毒中也是应该的,不过现在还是有
	//一半的概率
	
	//这个才是random判断命中应该用的算法,现在random用的太滥了.
	if( random(pp+dp)<pp )
	{
		level=me->query_skill("dugong",1);
		you->apply_condition("tm_poison", (level)/10 + 1 
			+ you->query_condition("tm_poison"));
		tell_object(me,"你成功地在"+name+"身上下毒。\n");
		return 1;
	}
	message_vision("$N下毒时被$n发现，事情败露。\n",me,you);
        me->kill_ob(you);
	you->kill_ob(me);
	return 1;
}



