//补满自己
void full()
{
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("force",query("max_force"));
}

//判断战斗的时候是否有其他人参与战斗
int fair_play(object me,object victim)
{
	object *ob;
	int	i;
	
	if( !me->is_fighting() ) return 1;
	ob = all_inventory(environment(me));
	i = sizeof(ob);
	while( i-- )
	{
		if( userp(ob[i]) && victim != ob[i] && me->is_fighting(ob[i]) ) return 0;
	}
	return 1;
}
