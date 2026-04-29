// baopinang.c
//written by tang

inherit ITEM;

void create()
{
	set_name("豹皮囊", ({ "baopinang", "bag", "nang" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("medicine", 0);
	set("poison", 0);
	set("dart", 0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "这是唐门弟子用来装暗器、毒药和解药的口袋。\n");
		set("no_sell", 1);
		}
}
  
void init()
{
	add_action("do_eatdrug", "jiedu");
	add_action("do_poison", "poison");
	add_action("do_throw", "throw");
}                                     

int do_eatdrug(string arg)
{              
	object obj;
                                          
               if( query("medicine") )
	{
		if ( !arg )
		{                    
			set("medicine",query("medicine")-1);
			message_vision("$N服下一包解毒药。\n",this_player());      
			this_player()->apply_condition("tm_poison", 0);
			return 1;
		}                                                               

		obj = present(arg, environment(this_player()));

		if( !objectp(obj) )
			return notify_fail("这里没有这个人。\n");           
		if( !obj->is_character() || obj->is_corpse() )
			return notify_fail("看清楚一点，那并不是活物。\n");

		set("medicine",query("medicine")-1);
		message_vision("$N喂$n吃下一颗解毒药。\n",this_player(),obj);
		obj->apply_condition("tm_poison", 0);
		return 1;
	}
	return notify_fail("你的解药已经用光了。\n");
}

int do_poison(string arg)
{   
	object me,you;
	int i,j;          
	string name;          
                      
	you = present(arg, environment(this_player()));

	if( !objectp(you) )
		return notify_fail("这里没有这个人。\n");           
	if( !you->is_character() || you->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
                                   
	name=you->query("name");

	me=this_player();
	i=me->query("int")+me->query_skill("literate",1)/10+me->query("cps")/3+me->query("spi")/3;
	i+=me->query_skill("dugong",1)/30;

	j=you->query("int")+you->query_skill("literate",1)/10+you->query("cps")/3+you->query("spi")/3;
	j+=you->query_skill("dugong",1)/30;

	if( me->is_busy() )	return notify_fail("你正在忙别的，腾不出手来下毒。\n");

	if ( query("poison") )
	{
		set("poison",query("poison")-1);
		if( i>j )
		{
			if( random(i-j)!=0 )
			{
				you->apply_condition("tm_poison", random(2) + 1 +
					you->query_condition("tm_poison"));
				tell_object(me,"你成功地在"+name+"身上下毒。\n");
				return 1;
			}
		}
		message_vision("$N下毒时被$n发现，事情败露。\n",me,you);
		return 1;
	}
	tell_object(me,"你已经没有毒药可下。\n"); 
	return 1;
}

int do_throw(string arg)
{                         
	object me,you,obj;
	int i,j,damage1,damage2;      
	string skill;            
                                                                                          
	me=this_player();
	you = present(arg, environment(this_player()));            
	obj=present("glove",me);

	if( !objectp(you) )
		return notify_fail("这里没有这个人。\n");           
	if( !you->is_character() || you->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
                       
	if( me->is_busy() )	return notify_fail("你正在忙别的，腾不出手来发暗器。\n");

	i=me->query("combat_exp");
               j=you->query("combat_exp");
                          
	if( j==0 )	j=1;
	i=100*i/j+200;

	if (me->is_fighting(you) )
	{
		if (query("dart"))
		{             
			set("dart",query("dart")-1);   
			me->start_busy(2);                                                

			if ( !obj || !obj->wear(me) )	
				me->apply_condition("tm_poison", random(2) + 1 +me->query_condition("tm_poison"));
			if ( random(i)>=199 )
			{
				damage1=me->query_skill("throwing",1);   
				skill=me->query_skill_mapped("throwing");
				damage2=me->query_skill(skill,1);   			
				damage1=damage1*damage2/100;
				you->set("kee", you->query("kee")-damage1);
				you->apply_condition("tm_poison", random(2) + 1 +
					you->query_condition("tm_poison"));
				message_vision("$n被$N发出的唐门暗器毒蒺藜射中。\n",me,you);
				return 1;
			}  

			message_vision("$n不慌不忙地躲过$N发出的毒蒺藜。\n",me,you);
			return 1;
		}       
		tell_object(me,"你已经无暗器可发了。\n");
		return 1;
	}
	tell_object(me,"你只能在战斗中发射暗器。\n");
	return 1;
}

int query_autoload()
{
    	if ( (string)this_player()->query("family/family_name")=="唐门" )	return 1;
	return 0;
}

