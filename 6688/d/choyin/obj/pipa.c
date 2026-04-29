// jade_pipa.c

inherit ITEM;

void create()
{
        set_name("玉石琵琶",({ "jade pipa", "pipa" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("value", 6000000);
                set("material", "jade");
                set("long", "一面用合田美玉做成的琵琶，上面雕刻着龙凤图案，也许可以用来弹奏？\n");
        }
}

void init()
{
        add_action("do_play", ("play") );
}

int do_play(string arg)
{
	object me, *ob;
	int i, skill, damage;

        if( !id(arg) ) return 0;

	me = this_player();
        message_vision("$N用" + name() + "弹奏出一支怪异的曲子。\n",
                this_player() );
	ob = all_inventory(environment(me));
	if( environment(me)->query("no_fight")) {
		this_player()->unconsious();
		return 1;
	}
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
   damage= 100-(int)ob[i]->query("max_force")/5+me->query("force_factor");
                if(damage<0) damage=0;
                if(ob[i]->query("combat_exp")>50000) damage=0;
		ob[i]->receive_damage("sen", damage);
		tell_object(ob[i], "你陶醉在这幽美的乐曲中，渐渐的失去了神志。\n");
		
	}

        return 1;
}
