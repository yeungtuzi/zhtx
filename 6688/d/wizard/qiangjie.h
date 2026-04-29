int find_money(object ob)
{
	object *inv,obj=this_object();
	int i,value=0;

	obj->add("xunhuan_amount",1);
	if(obj->query("xunhuan_amount") > 10) return 1;

	if(ob->query("money_id")) value += ob->value();

	inv=all_inventory(ob);
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query_max_encumbrance()) find_money(inv[i]);
		if(inv[i]->query("money_id")) value += inv[i]->value();
	}
	obj->add("all_value_of_player",value);

	if(obj->query("xunhuan_amount") > 10) return -100;
	else return obj->query("all_value_of_player");
}

void init()
{
	object me,*inv,wo,fei,obj=this_object();
	int i,value=0,find_flag=0;

        if ( userp(me = this_player()) )
	{
		obj->set("xunhuan_amount",0);
		obj->set("all_value_of_player",0);
		value=find_money(me);
		obj->set("all_value_of_player",0);
		obj->set("xunhuan_amount",0);
	}

	if(value==-100)
	{
		message_vision(HIR"$N的钱藏的太深了吧。\n"NOR,me);
		me->set_temp("my_money",0);
	}
	else
		me->set_temp("my_money",value);

	if( value==-100 || value >= 50000 )
	{
	    if(fei=present("jiefei",obj) )
	    {
		if(userp(fei)) return;
		message_vision(HIR"$N对$n大喝一声：\n"+
			"此路是我开，此树是我栽，要想从此过，留下买路钱。\n"NOR,fei,me);
		return;
	    }

	    if( (random(value) > 50000 && random(4)==1) || value==-100)
	    {
		if ( !(wo=find_object("/d/wizard/jiefeiwo")) )
			wo=clone_object("/d/wizard/jiefeiwo");
		inv=all_inventory(wo);
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->id("jiefei") 
				&& inv[i]->query("position")==POSITION)
			{
				fei=inv[i];
				find_flag=1;
			}
		}
		if( !find_flag )
		{
			fei=new("/d/wizard/npc/jiefei");
			fei->set("position",POSITION);
		}

		fei->move(obj);
		message_vision(HIR"一个$N突然来到$n的面前，大喝一声：\n"+
			"此路是我开，此树是我栽，要想从此过，留下买路钱。\n"NOR,fei,me);
	    }
	}
	return;
}

int valid_leave(object me, string dir)
{
        object fei,*ob,money,obj=this_object();
	int i,value=0,value1=0,gold,silver,amount=0,temp;

        if ( fei=present("jiefei", obj) )
        {
		if(userp(fei)) return ::valid_leave(me, dir);
		
		obj->set("all_value_of_player",0);
		obj->set("xunhuan_amount",0);
		value=find_money(me);
		obj->set("all_value_of_player",0);
		obj->set("xunhuan_amount",0);

		if(value==-100)
			return notify_fail(HIR"你的钱藏的太深了吧。\n"NOR);

		if( value >= 50000 && !me->query_temp("can_pass"))
			return notify_fail("劫匪大喝一声：不交钱，休想过去。\n");
		if( value>me->query_temp("my_money"))
		{
			message_vision(HIR"$N对$n嘿嘿笑道：\n"+
				"想趁火打劫？快把多余的钱交出来，否则休怪我不客气。\n"NOR,fei,me);
			return 0;
		}
		me->delete_temp("my_money");

		ob=all_inventory(obj);
		for(i=0;i<sizeof(ob);i++)
		{
			if(userp(ob[i]))  amount++;
			if( living(ob[i]) || userp(ob[i]) ) continue;

			obj->set("all_value_of_player",0);
			obj->set("xunhuan_amount",0);
			temp = find_money(ob[i])*3/4;
			obj->set("all_value_of_player",0);
			obj->set("xunhuan_amount",0);

			if(temp==-100*3/4)
			{
				message_vision("$N拾起了地上的"+ob[i]->name()+"。\n",fei);
				destruct(ob[i]);
			}

			if(temp > 0)
			{
				value1 +=temp;
				message_vision("$N拾起了地上的"+ob[i]->name()+"。\n",fei);
				destruct(ob[i]);
			}
		}

		if(value1 >= 100)
		{
			gold = value1/10000;
			silver = (value1%10000)/100;
			if(gold > 0)
			{
				money=new("/obj/money/gold");
				money->set_amount(gold);
				money->move(fei);
			}
			if(silver > 0)
			{
				money=new("/obj/money/silver");
				money->set_amount(silver);
				money->move(fei);
			}
		}
		
		if(amount == 1 )
			fei->move("/d/wizard/jiefeiwo");
		me->delete_temp("can_pass");
        }
        return ::valid_leave(me, dir);
}
