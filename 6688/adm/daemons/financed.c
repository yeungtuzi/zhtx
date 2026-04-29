inherit F_DBASE;

int create()
{
	seteuid(getuid());
	set("channel_id", "财政精灵");	

}	

void get_taxes(object user)
{
        object tencash,cash,gold;
        int tencash_old,cash_old,gold_old,sum,tencash_new,cash_new,gold_new;
	int oldsum;

        tencash_old=0;
        tencash_new=0;
        tencash=present("tenthousand-cash_money",user);
        if (tencash)
        {
                tencash_old=tencash->query_amount();
                tencash_new=tencash_old;
                if (tencash_new>100)
                {
                        tencash_new=100;
                }
        }
        cash_old=0;
        cash_new=0;
        cash=present("thousand-cash_money",user);
        if (cash)
        {
                cash_old=cash->query_amount();

                cash_new=cash_old;
                if (cash_new>1000)
                {
                        cash_new=1000;
                }
        }
        gold_old=0;
        gold_new=0;
        gold=present("gold_money",user);
        if (gold)
        {
                gold_old=gold->query_amount();
                gold_new=gold_old;
        }
        sum=tencash_new*100+cash_new*10+gold_new;
	oldsum = sum;
        if (sum>10000)
        {
                sum=10000;
        }
        if (sum>5000)
        {
                sum=sum-(sum-5000)*80/100-1500-600-180;
        } else {
                if (sum>2500)
                {
                        sum=sum-(sum-2500)*60/100-600-180;
                } else {
                        if (sum>1000)
                        {
                                sum=sum-(sum-1000)*40/100-180;
                        } else {
                                if (sum>100)
                                {
                                        sum=sum-(sum-100)*20/100;
                                }
				else {
				  if (sum > 10) 
					sum=sum-(sum-10)*10/100;	
				}
                        }
                }
        }

	oldsum = oldsum - sum;
        tencash_new=sum/100;
        sum=sum%100;
        cash_new=sum/10;
        sum=sum%10;
        gold_new=sum;


        if (!gold)
        {
	   if(gold_new) {
                gold=new("/obj/money/gold");
                gold->move(user);
                gold->set_amount(gold_new);
	   }
        } else {
                gold->add_amount(gold_new-gold_old);
        }
        if (!cash)
        {
	   if(cash_new) {
                cash=new("/obj/money/thousand-cash");
                cash->move(user);
                cash->set_amount(cash_new);
	    }
        } else {
                cash->add_amount(cash_new-cash_old);
        }

        if (!tencash)
        {
	   if(tencash_new) {
                tencash=new("/obj/money/tenthousand-cash");
                tencash->move(user);
                tencash->set_amount(tencash_new);
	    }
        } else {
                tencash->add_amount(tencash_new-tencash_old);
        }
	if(oldsum ) tell_object(user,"\n\n你携带了过多的现金，已经依法扣除现金流通税!\n\n");

}

