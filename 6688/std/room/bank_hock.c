#include <ansi.h>

inherit BANK;

int is_broken(object ob)
{
	object base_ob;
	
	base_ob = new(base_name(ob));
	if( !objectp(base_ob) ) return 1;
	if( base_ob->query("value") != ob->query("value") )
	{ 
		destruct(base_ob);
		return 1;
	}
	destruct(base_ob);
	return 0;
}

void init()
{
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        ::init();
}

string value_string(int value)
{
        if( value < 1 ) value = 1;
        else if( value < 100 )
                return chinese_number(value) + "文钱";
        else
                return chinese_number(value/100) + "两"
                        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)

{
        object ob;

        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int do_value(string arg)
{
        object ob;
        int value;

        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要拿什麽物品给当铺估价？\n");

        if( ob->query("money_id") )
                return notify_fail("这是「钱」，你没见过吗？\n");
    
        value = ob->query("value");
        if( !value ) printf("%s一文不值。\n", ob->query("name"));
        else{
              if( !ob->query("unpawnable"))
                printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s。\n如果卖断(sell)，可以拿到%s。\n",
                        ob->query("name"), value_string(value),
                        value_string(value/2 ), value_string(value * 4/5));
               else
                 printf("你不能典当%s。\n如果卖断(sell)，可以拿到%s。\n",
                      ob->query("name"),value_string(value * 4/5));
        }

        return 1;
}

int do_pawn(string arg)
{
        object ob;
        string term, *terms;
        string data,reason, pawn_list;
        int value, pawn_count, i, each_amount, already_exist;
        int rvalue, max_pawn,exp;
        mapping pawn,apawn,fpawn;
        object me;
        me = this_player();
        pawn = me->query("pawn");
        apawn = me->query("apawn");
        fpawn = me->query("fpawn");

        exp = (int)me->query("combat_exp");
        max_pawn = 10 + exp/90000;
        if(exp > 5000 && max_pawn < 20 ) max_pawn = 20;
        if (me->is_busy()) return notify_fail("你现在正忙着呢，不能典当东西。\n");

        
        if( !arg || !(ob = present(arg, this_player())) )
        {
	printf("\n你最多能典当%d种物品.\n",max_pawn);
        write("你目前典当的物品有：\n");
        if( !mapp(pawn) ||   !sizeof(pawn) )
                write("\t没有任何典当的物品。\n");
        else {
                        terms = keys(pawn);
                        pawn_list = "";
                        for(i=0; i<sizeof(terms); i++)
                        {
                         	if( undefinedp(apawn) || undefinedp(apawn[terms[i]]) || !apawn[terms[i]] )
                         	{
                         		me->set("apawn/"+terms[i],1);
                         		each_amount = 1;
                         	}
                         	else
                         		each_amount = (int)apawn[terms[i]];
                                pawn_list += sprintf("%-3s：  %-18s    共%-2d件    每件赎银：%s\n", terms[i], pawn[terms[i]], each_amount,
                                                value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
                        }
                        me->save();
                        me->start_more(pawn_list);
              }
        return 1;
        }
        if( ob->query("money_id") )     return notify_fail("你要当「钱」？\n");

	if( ob->is_character() ) return notify_fail("救命啊！居然有人要卖活人哪！！！\n");
	if( is_broken(ob) ) return notify_fail("小店可不是收破烂的！\n");

        value = ob->query("value");
        if( !(value/4) ) return notify_fail("这样东西并不值很多钱。\n");
        if( ob->query("shaolin") ) 
           return notify_fail("这是佛门的东西，小店可不敢收，真是罪过！\n");

        // added to check the reason
        reason = ob->cannot_pawn();
        if( reason != "" && reason != 0)
        {
                if(stringp(reason))
                        return notify_fail(reason);
                else
                        return notify_fail("你不能典当" + ob->query("name") + "\n");
        }
	//新人10种,360万经验50种     yeung
	
	//防止执行时段错误导致物品增多 yeung
	ob->move("/std/room/hockshop");
	
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > max_pawn)
                        return notify_fail("你已典当太多物品了。\n");
                        for(i=0; i<sizeof(terms); i++)  
                        {
                        pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
                        }
                }
        else pawn_count = 0;
        term = ob->query("name");
        data = base_name(ob)+ ".c";

        if( !ob->query("unpawnable") ) {
		//按种类当 yeung
		already_exist = 0;

                if( pawn_count )
                {
                	terms = keys(pawn);
                	for(i=0; i<sizeof(terms); i++)  
                	{
				if( fpawn[terms[i]] == data) //有相同的物件在那里
 				{
 					me->add("apawn/"+terms[i],1);
 					already_exist = 1;
 					break;
 				}                       
                	}
                }
		if( !already_exist )
		{
                	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
                	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
                	me->set("fpawn/"+sprintf("%d",pawn_count), data);
                	me->set("apawn/"+sprintf("%d",pawn_count), 1);
		}
                me->save();
                message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
                        + value_string(value  / 2) + "。\n", this_player());

                pay_player(this_player(), value  / 2 );
                destruct(ob);
        }
        else
         tell_object(me,"你不能典当" + ob->query("name") + "\n");

        return 1;
}

int do_sell(string arg)
{
        object ob;
        int value;

        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("你要卖断什麽物品？\n");

        if( ob->query("money_id") )     return notify_fail("你要卖「钱」？\n");
        value = ob->query("value");
        if( !value ) return notify_fail("这样东西不值钱。\n");
        if( ob->query("shaolin") )
           return notify_fail("这是佛门的东西，小店可不敢收，真是罪过！\n");
        if (ob->query("no_sell")) return notify_fail("这样东西不能卖。\n");

 

        message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",
                this_player());

        pay_player(this_player(), value  * 4 / 5);
        destruct(ob);

        return 1;
}
void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


        if( amount < 1 ) amount = 1;
        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        mapping pawn,apawn,fpawn;
        object me;
        int afford;

        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("指令格式：redeem <物品标号>\n");

        me = this_player();

        apawn = me->query("apawn");
        if (me->is_busy()) return notify_fail("你现在正忙着呢，不能赎东西。\n");

        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("有这个物品标号吗？\n");

        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {

                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                if(!ob->query("unpawnable"))
                        ob->move(me);
                else 
                        {
                                tell_object(me,"这是禁物，已经被朝廷收去了，你认倒霉吧！\n");
                                ob->destruct();
                        }
		if( apawn[sprintf("%d",num)] > 1 )
		{
			me->add("apawn/"+sprintf("%d",num),-1);
		}
		else
                {
                	me->delete("pawn/"+sprintf("%d",num));
                	me->delete("vpawn/"+sprintf("%d",num));
                	me->delete("fpawn/"+sprintf("%d",num));
                	me->delete("apawn/"+sprintf("%d",num));
                }
                me->save();
                       me->start_busy(1);
                message_vision("$N赎回了$n。\n", me, ob);
                return 1;
        } else
                return notify_fail("你的钱不够。\n");

}
