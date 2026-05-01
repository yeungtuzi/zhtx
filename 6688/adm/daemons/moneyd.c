// moneyd.c  钱的功能

// by Xiang@XKX (95/12/22)

string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "文铜板";
        return output;
}

string price_str(int amount)
{
        // returns a chinese string of `amount` of money
	string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
		if (output != "")
                	output += "又" + chinese_number(amount / 100) + "两白银";
		else
			output = chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount)
		if (output != "")
                	return output + "又" + chinese_number(amount) + "文铜板";
		else
			return chinese_number(amount) + "文铜板";
        return output;
}

void pay_player(object who, int amount)
{
        int v;
        object ob;

	seteuid(getuid());
        if (amount < 1)
                amount = 1;
        if (v = amount / 10000) {
                ob = new(GOLD_OB);
                ob->set_amount(amount / 10000);
                ob->move(who);
                amount %= 10000;
        }
        if (amount / 100) {
                ob = new(SILVER_OB);
                ob->set_amount(amount / 100);
                ob->move(who);
                amount %= 100;
        }
        if (amount) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int player_pay(object who, int amount)
{
	object tencash_ob,cash_ob,g_ob, s_ob, c_ob;
	int tencash,cash,gc, sc, cc, left;

	seteuid(getuid());
        if (who->busy()) return notify_fail("你忙着呢!/n");

	if (tencash_ob = present("tenthousand-cash_money", who))
		tencash = tencash_ob->query_amount();
	else
		tencash = 0;

	if (cash_ob = present("thousand-cash_money", who))
		cash = cash_ob->query_amount();
	else
		cash = 0;

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;

	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	left = cc + sc * 100 + gc * 10000 + cash * 100000 + tencash * 1000000;
	
	if( left < amount ) 
		return 0;
	else {
		left -= amount;

/*
		mage=who->query("age")-13;
		mage=mage*mage*10000;
		if (left>mage) left=mage;
*/
		tencash = left / 1000000;
		left = left %1000000;
		cash =left / 100000;
		left = left % 100000;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

//CHANNEL_D->do_channel(this_player(),"sys",sprintf("gc = %d\n",gc));

		if (tencash_ob){
                        if(tencash)
			tencash_ob->set_amount(tencash);
                        else
                          destruct(tencash_ob);
                }
		else if( tencash ) {
			tencash_ob = new(TECASH_OB);
			tencash_ob->set_amount(tencash);
			tencash_ob->move(who);
		}

		if (cash_ob)
		 	cash_ob->set_amount(cash);
		else if (cash) {
			cash_ob = new(THCASH_OB);
			cash_ob->set_amount(cash);
			cash_ob->move(who);
		}

		if (g_ob)
		 	g_ob->set_amount(gc);
		else if (gc) {
			g_ob = new(GOLD_OB);
			g_ob->set_amount(gc);
			g_ob->move(who);
		}

		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}

		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}

		return 1;
	}
}
