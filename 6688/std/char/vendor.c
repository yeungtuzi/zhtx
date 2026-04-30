// vendor.c

#include <dbase.h>

void reset()
{
	//简单的reload_object会出问题，避免那种身蓋的东西越来越多的情况，容易导致房间出问题
	object *inv;
	int i;

	inv = all_inventory(this_object());
	i = sizeof(inv);
	while(i--)
	{
		if( !inv[i] || !objectp(inv[i]) ) continue;	
		if( !userp(inv[i]) ){ destruct(inv[i]); continue;}
		inv[i]->move(VOID_OB);
	}
//	write("hehe \n");
	reload_object(this_object());
}

string accept_buy(object me, string what)
{
	mapping list;
	string *item;
	int i, index;
	string what_name;

	if( sscanf(what, "%s %d", what_name, index) != 2 ) {
		index = 1;
//	here if what == " a b" then what_name="a" now
//	so reset what_name , by cmy 971204
		what_name = what;
	}
	if( mapp(list = query("vendor_goods")) ) {
		item = keys(list);
		for(i=0; i<sizeof(item); i++) {
			if( item[i]->id(what_name) ) {
				--index;
				if( !index )
					if(list[item[i]]) return item[i];
			}
		}
	}

	return 0;
}

int query_trading_price(string handle)
{
	mapping list;

	if( !mapp(list = query("vendor_goods")) )
		return 0;
	if( undefinedp(list[handle]) ) return 0;

	if( list[handle] <= -2 ) return handle->query("value")*15/10;

	return handle->query("value");
}

void compelete_trade(object me, string what)
{
	mapping list;
	// 2026-04-30: unused variable commented out
	// string ob_file;
	object ob;

	list = query("vendor_goods");
	if( !undefinedp(list[what]) ) {
		if(list[what] > 1) list[what] -= 1;
		else if(list[what] == 1) map_delete(list,what);
		else if(list[what] == -2) map_delete(list,what);
		else if(list[what] < -2) list[what] += 1;

		set("vendor_goods",list);

		ob = new(what);
		ob->move(me);
		message_vision("$N向$n买下一" + ob->query("unit") + ob->query("name") + "。\n",
			me, this_object() );
	}
}

string price_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两银子"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

int do_vendor_list(string arg)
{
	mapping goods=([]);
	string list, *name;
	int i;

	if( mapp(query("vendor_goods")) ) goods=query("vendor_goods");
	if( arg && !this_object()->id(arg) ) return 0;
	name = keys(goods);
	list = "你可以购买下列这些东西：\n\n";
	for(i=0; i<sizeof(name); i++)
	{
		if( goods[name[i]] > 0 )
			list += sprintf("  %-25s： 数量（%-8d）  每%s%s\n",
				name[i]->short(),
				goods[name[i]],
				name[i]->query("unit"),
				price_string(name[i]->query("value")) );
		else if( goods[name[i]] == -1 )
			list += sprintf("  %-25s： 数量（%-8s）  每%s%s\n",
				name[i]->short(),
				"无穷",
				name[i]->query("unit"),
				price_string(name[i]->query("value")) );

		else if( goods[name[i]] <= -2 )
			list += sprintf("  %-25s： 数量（%-8d）  每%s%s\n",
				name[i]->short(),
				-(goods[name[i]]+1),
				name[i]->query("unit"),
				price_string(name[i]->query("value")*15/10) );
	}
	write(list);
	return 1;	
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要估什么的价？\n");
	
	if (ob->query("money_id"))
		return notify_fail("你没用过钱啊？\n");

	value = ob->query("value");
	if (value < 10)
		printf("%s一文不值。\n", ob->name());
	else 
		printf("%s价值%s。\n如果卖断(sell)，可以拿到%s。\n",
			ob->name(), price_string(value),
			price_string(value * 4/5));
	return 1;
}

int do_sell(string arg)
{
	mapping goods=([]);
	string file, *name;
	object ob;
	int value;
	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要卖什么？\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (ob->query("no_drop"))
		return notify_fail("这样东西不能卖。\n");

           if(ob->query("no_sell")||ob->query("unpawnable"))
		return notify_fail("这样东西不能卖。\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");

        if( ob->query("shaolin") )
           return notify_fail("这是佛门的东西，小店可不敢收，真是罪过！\n");

	value = ob->query("value");
	if (value < 10)
		write(ob->name() + "一文不值！\n");
	else {
		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->name() + "给$n。\n", this_player(), this_object());

		MONEY_D->pay_player(this_player(), value*4/5);

		file=file_name(ob);
		file=file[0..(strsrch(file,"#")-1)];
//提前到这里防止中断导致物品增多
		destruct(ob);
		if( !mapp(query("vendor_goods")) )  goods[file]=-2;
		else
		{
			goods=query("vendor_goods");
			if( undefinedp(goods[file]) )  goods[file]=-2;
			else
			{
				if(goods[file] >= 0) goods[file]+=1;
				else if(goods[file] <= -2) goods[file]-=1;
			}
		}
		set("vendor_goods",goods);
	//	destruct(ob);
	}
	return 1;
}
