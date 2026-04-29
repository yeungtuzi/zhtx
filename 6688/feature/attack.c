// attack.c

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

nosave object charge_target = 0;
nosave object *enemy = ({});
nosave object *killer = ({});

object *query_enemy() { return enemy; }
object *query_killer() { return killer; }
object query_charge_target() { return charge_target; }

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(object ob)
{
	if( !ob ) return sizeof(killer) > 0;
	return member_array(ob, killer)!=-1;
}

varargs int is_charging(object ob)
{
	if( !ob )
		return objectp(charge_target) && (member_array(charge_target, enemy)!=-1);
	return (ob==charge_target) && (member_array(ob, enemy)!=-1);
}

//This function starts fight between this_object() and ob
void fight_ob(object ob)
{
	if(!ob || ob==this_object()) return;

	set_heart_beat(1);

	if( member_array(ob, enemy)==-1 )
		enemy += ({ ob });
}

//this function starts killing between this_object() and ob
//but not show the message.
void bihua_ob(object ob)
{
	if( member_array(ob, killer)==-1 )
		killer += ({ ob });
	fight_ob(ob);
}

// This function starts killing between this_object() and ob
void kill_ob(object ob)
{
	object *guards,me=this_object();

	if( member_array(ob, killer)==-1 )
		killer += ({ ob });

	if( this_object()->query("id")=="wolf dog" )

	tell_object(ob, HIR "看起来" + me->name() + "想杀死你！\n" NOR);

	if( userp(ob) && userp(me) && ob->query_temp("pk_id") 
		&& member_array(me->query("id"),ob->query_temp("pk_id"))!=-1 )
	{
		tell_object(me,HIW"你开始反击"+ob->name()+"。\n"NOR);
	}
	else if( userp(ob) && userp(me) )
	{
		if( !me->query_temp("pk_id") 
			|| member_array(ob->query("id"),me->query_temp("pk_id"))==-1 )
			me->add_temp("pk_id",({ob->query("id")}) );
		tell_object(me,HIW"你开始主动pk"+ob->name()+"。\n"NOR);
	}

	// for menpai guard
	ob->killing_master(this_object());

	// If we were protecting the target, cancel the protection.
	if( ob==query_temp("guarding") ) {
		delete_temp("guarding");
		guards = ob->query_temp("guarded");
		guards -= ({ this_object() });
		ob->set_temp("guarded", guards);
		tell_object(this_object(), HIY "你停止保护" + ob->name() + "。\n" NOR);
		tell_object(ob, HIY + this_object()->name() + "停止保护你。\n" NOR);
	}

	// Check if anyone are is guarding the target, let them join the combat too.
	if( arrayp(guards = ob->query_temp("guarded")) ) {
		guards = filter_array(guards, (:
				objectp($1)
			&&	living($1)
			&&	$1 != this_object()
			&&	present($1, environment())
			&&	!is_fighting($1)
			&&	$1->visible(this_object()) :));
		if( sizeof(guards) > 0 ) {
			// guards must be added to enemy prior to call guards join the fight
			// thus can prevent infinite loop in the mutual guard case.
			enemy += guards;
			message("vision", HIR + ob->name() + "受到攻击！你挺身加入战团！\n" NOR,
				guards);
			guards->kill_ob(this_object());
		}
	}
	fight_ob(ob);
	if( this_object()->query("id")=="wolf dog" ) CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O [DBG] kill_ob end: enemy=%d killer=%d", this_object(), sizeof(enemy), sizeof(killer)));
}

// This function promotes ob to the first ordered target to attack.
void charge_ob(object ob)
{
	if( !arrayp(enemy) || member_array(ob, enemy)==-1 ) return;
	enemy -= ({ ob });
	enemy = ({ ob }) + enemy;	
	tell_object(this_object(), HIY "你选择" + ob->name() + "为首要攻击目标！\n" NOR);
	charge_target = ob;
}

varargs void ally_ob(object ob,int coefficient)
{
	object *obj,*partner,me=this_object();
	int i;

	if(arrayp(me->query_temp("ally/partner")))
	{
		obj=me->query_temp("ally/partner");
		obj+=({me});
		if(member_array(ob,obj)==-1)  obj+=({ob});
	}
	else
		obj=({me,ob});

	i=sizeof(obj);
	while(i--)
	{
		partner=obj;
		obj[i]->set_temp("ally/partner",partner-({obj[i]}));
		if(coefficient)
			obj[i]->set_temp("ally/coefficient",coefficient);
		else
			obj[i]->set_temp("ally/coefficient",100);
	}
}

void clean_up_enemy()
{
	int before = sizeof(enemy);
	enemy = filter_array(enemy, (:
		objectp($1)
		&& (environment($1)==environment($2))
		//&& ($2->visible($1))
		&& (living($1) || is_killing($1))
	:), this_object() );
	if( this_object()->query("id")=="wolf dog" && before != sizeof(enemy) )
		CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O [CL] enemy %d->%d killer=%d", this_object(), before, sizeof(enemy), sizeof(killer)));                                		

	if( sizeof(enemy) > 0 ) {
		for(int i=0; i<sizeof(enemy); i++) 
		{
			if(  !living(enemy[i]) && is_killing(enemy[i]) && (enemy[i]->query_per()/2+random(enemy[i]->query_per()))>(this_object()->query_wil()+query("bellicosity")/10+query("cps")) )
			{                    
				message_vision("$N看了看昏迷在地上的$n的样子，叹了口气，实在不忍心动手。\n",this_object(),enemy[i]);				
				if( environment(enemy[i])->query("no_death") )
					enemy[i]->set_temp("be_defeated",1);
				enemy[i] = 0;
			}	
		}
		enemy -= ({ 0 });
	}

}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	if( charge_target && member_array(charge_target, enemy)!=-1 )
		return charge_target;

	which = random(sizeof(enemy));

	return which < MAX_OPPONENT ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	object *obj;

	if( is_killing(ob) && present(ob,environment(this_object())) ) return 0;

	enemy -= ({ ob });

	if(obj=ob->query_temp("ally/partner"))
	{
		int i;

		ob->delete_temp("ally");

		i=sizeof(obj);
		while(i--)
		{
			if(objectp(obj[i]))
			{
				obj[i]->delete_temp("ally");
				remove_enemy(obj[i]);
				obj[i]->remove_enemy(this_object());
			}
		}
		message_vision(HIW "联合攻击终止。\n" NOR,ob);
	}
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob) ) {
		killer -= ({ ob });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop charging specific target
int remove_charge()
{
	charge_target = 0;
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	if( this_object()->query("id")=="wolf dog" ) CHANNEL_D->do_channel(this_object(), "sys", "[DEBUG] remove_all_enemy");
	object me=this_object();
	int i;

	for(i=0; i<sizeof(enemy); i++) {
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) ) enemy[i]->remove_enemy(me);
		enemy[i] = 0;;
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	if( this_object()->query("id")=="wolf dog" ) CHANNEL_D->do_channel(this_object(), "sys", "[DEBUG] remove_all_killer");
	object *ob;
	int i;

	killer = ({});
	enemy -= ({ 0 });

	for(i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
			enemy[i] = 0;;

	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
{
	object me,ob;
	string type, skill;
	mapping prepare;

	me= this_object();
	prepare = query_skill_prepare();	

	if( ob = query_temp("weapon") )
		type = ob->query("skill_type");
//	else 
//		type = "unarmed";
//copy from xkx cmy971020
        else if ( sizeof(prepare) == 0) type = "unarmed";
        else if ( sizeof(prepare) == 1) type = (keys(prepare))[0];
        else if ( sizeof(prepare) == 2)
		type = (keys(prepare))[query_temp("action_flag")];

	if( stringp(skill = query_skill_mapped(type)) ) {
		// If using a mapped skill, call the skill daemon.
                if ( ob )
                        set("actions", (: call_other, SKILL_D(skill), "query_action", me, ob :) );
                else

			set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
	} else {
		// Else, let weapon handle it.
		if( ob ) set("actions", ob->query("actions",1) );
		else set("actions", query("default_actions",1) );
	}
}

// This is called in heart_beat() to perform attack action.
protected int attack()
{
	object opponent;
	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else {
		if( this_object()->query("id")=="wolf dog")
			CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O [DEBUG] no opponent, enemy=%d killer=%d fighting=%d", this_object(), sizeof(enemy), sizeof(killer), is_fighting()));
		return 0;
	}
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob;
	string vendetta_mark;

	// We check these conditions here prior to handle auto fights. Although
	// most of these conditions are checked again in COMBAT_D's auto_fight()
	// function, these check reduces lots of possible failure in the call_out
	// launched by auto_fight() and saves some overhead.
	if(	is_fighting()
	||	!living(this_object())
	||	!(ob = this_player())
	||	!this_object()->visible(ob)
	||	environment(ob)!=environment()
	||	!living(ob)
	||	ob->query("linkdead") )
		return;

	// Now start check the auto fight cases.
	if( userp(ob) && is_killing(ob) ) {
		COMBAT_D->auto_fight(this_object(), ob, "hatred");
		return;
	} else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) ) {
		COMBAT_D->auto_fight(this_object(), ob, "vendetta");
		return;
	} else if( userp(ob) && (string)query("attitude")=="aggressive" ) {
		COMBAT_D->auto_fight(this_object(), ob, "aggressive");
		return;
	} else if( random((int)query("bellicosity") / 40) > (int)query("cps") ) {
		COMBAT_D->auto_fight(this_object(), ob, "berserk");
		return;
	}
}
