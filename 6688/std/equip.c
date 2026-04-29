// equip.c

inherit ITEM;
inherit F_EQUIP;

void setup()
{
	if( clonep(this_object()) ) return;

	if( weight() > 30000 ) {
		if( query("armor_prop") && !query("armor_prop/dodge") )
			set("armor_prop/dodge", - weight() / 3000 );
		if( query("weapon_prop") && !query("weapon_prop/dodge") )
			set("weapon_prop/dodge", - weight() / 3000 );
	}
}

varargs void init_weapon(string owner,string name,string id,string namelong,string type,int damage,int attack,int dodge,int parry,int defense)
{
	object me;
	me = this_object();
	me->set("owner",owner);
	me->set_name(name, ({ id,type }));
	me->set("weapon_prop/damage", damage);
	if( stringp(namelong) )
	{
		if( namelong[-1..0] != "\n" )
			namelong += "\n";
		me->set("long",namelong);
	}                                  
	me->set("weapon_prop/attack",attack);
	me->set("weapon_prop/dodge",dodge);
	me->set("weapon_prop/parry",parry);
	me->set("weapon_prop/defense",defense);		
	me->setup();		      
	me->set("value",0);
	me->set("no_get",1);
	me->set("no_drop",1);
	return;
}	

varargs void init_cloth(string owner,string name,string id,string namelong,string type,int armor,int attack,int dodge,int parry,int defense)
{
	object me;
	me = this_object();
	me->set("owner",owner);
	me->set_name(name, ({ id,type }));
	me->set("armor_type", type);
	me->set("armor_prop/armor", armor);
	if( stringp(namelong) )
	{
		if( namelong[-1..0] != "\n" )
			namelong += "\n";
		me->set("long",namelong);
	}                                  
	me->set("armor_prop/attack",attack);
	me->set("armor_prop/dodge",dodge);
	me->set("armor_prop/parry",parry);
	me->set("armor_prop/defense",defense);		
	me->setup();		      
	me->set("value",0);
	me->set("no_get",1);
	me->set("no_drop",1);
	return;
}	