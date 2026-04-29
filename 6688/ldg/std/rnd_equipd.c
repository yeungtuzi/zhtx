// rnd_equip.c
//
// This is the "daemon dispatcher" that provide a link to varius skill
// daemons.

#define EQUIPDIR "/ldg/obj/random_equip/"
string *equip_daemons=({});

int make_equip( )
{
	int i,len;
	string name,*equip_name;

	equip_name=get_dir(EQUIPDIR);
	i=sizeof(equip_name);
	while(i--)
	{
		len=sizeof(equip_name[i]);
		if ( equip_name[i][(len-2)..(len-1)]==".c" )
		{
			name=equip_name[i][0..(len-3)];
			equip_daemons+=({EQUIPDIR+name});
		}
	}
	return 1;
}

varargs string rnd_equip()
{
	if( !stringp(equip_daemons) || !sizeof(equip_daemons) )  make_equip();
	return equip_daemons[random(sizeof(equip_daemons))];
}

mixed carry_rnd_equip(int low,int high)
{
	object ob;
	int level;
	
        if( !clonep() ) return VOID_OB;

        if( !objectp(ob = new(rnd_equip()))) return 0;

        if( ob->violate_unique() ) ob = ob->create_replica();
        if( !ob ) return VOID_OB;
	
	//CHANNEL_D->do_channel(this_object(),"sys","level:"+sprintf("%d",level));
	ob->random_generate(-1);
	level=ob->query("level");
	if(level<low)
	{
		level=low;
		ob->random_generate(level);
	}
	else if(level>high)
	{
		level=high;
		ob->random_generate(level);
	}
	ob->move(this_object());
	return ob;
}
