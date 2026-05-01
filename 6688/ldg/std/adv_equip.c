// adv_equip.c
// by meteoric

#include <ansi.h>
#include <dbase.h>
#include "/ldg/std/adv_weapon.h"
#define ADV_EQUIP_LIMITED 20

inherit ITEM;
void add_additional_prop(object who);
void remove_additional_prop(object who);
int attach();
int detach();

void setup()
{
	set("unpawnable", 1);
	set("no_sell",1);
	set("no_get",1);
	set("no_drop",1);
}

varargs int move(mixed dest, int silently)
{
	object ob;
	
	if( objectp(dest)) ob = dest;
        else if( stringp(dest) ) {
                call_other(dest, "???");
                ob = find_object(dest);
                if(!ob) error("move: destination unavailable.\n");
        	} 
        else error(sprintf("move: arg 0 object or string expected, %s passed.\n", typeof(dest)));
	
	::move(ob,silently);
	
	attach();
	return 1;
}

int attach()
{
	mapping equips;
	object owner;
	string file;
	mixed *props;
	mapping prop;
	int adv_equip_id;
	
	if(!(owner = environment())) return 0;
		
	if(!userp(owner)) return 0;
	
	if(query("attached")) return 0;
	
	if(!(prop=query("adv_props"))) return 0;
	
	set("attached",1);
	owner->set_temp("loaded_adv_equip",1);//reload equip的标志
	adv_equip_id=owner->query("total_adv_equip_num")+1;
	owner->set("total_adv_equip_num",adv_equip_id); //设定adv_equip的unique Number
	set("unique_id",adv_equip_id);
	
	if(!equips=owner->query("adv_equips")) equips=([]);
	
	file=base_name(this_object());
	file=file+"#"+sprintf("%d",adv_equip_id);

	props=({adv_equip_id});
	props+=({query("ename")});
	props+=({query("level")});
	props+=({prop});
	
	equips[file]=props;
	
	owner->set("adv_equips",equips);
	return 1;
}

int detach()
{
	mapping equips;
	object owner;
	string file;
	
	if(!(owner = environment())) return 0;
	
	if(!userp(owner)) return 0;
	
	if(!equips=owner->query("adv_equips")) equips=([]);
	
	file=base_name(this_object());
	file=file+"#"+sprintf("%d",query("unique_id"));

	map_delete(equips,file);
	owner->set("adv_equips",equips);
	destruct(this_object());
	return 1;
}

int wear()
{
	object owner;
	mapping armor_prop, applied_prop,adv_armor_prop,equips;
	string *apply,*adv_apply,type;
	string file;

	// Only character object can wear armors.
	if( !(owner = environment())->is_character() ) return 0;

        file=base_name(this_object());
        file=file+"#"+sprintf("%d",query("unique_id"));

	if( userp(owner) && (!mapp(equips=owner->query("adv_equips")) || !arrayp(equips[file])) )
	{
		destruct(this_object());
		tell_object(owner,"这不是你的东西。\n");
		return 0;
	}

	// If already worn, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "armor_prop" defined.
	if( !mapp(armor_prop = query("armor_prop")) )
		return notify_fail("你只能穿戴可当作护具的东西。\n");
	// check if have advanced property
	
	type = query("armor_type");
	if( owner->query_temp("armor/" + type) )
		return notify_fail("你已经穿戴了同类型的护具了。\n");
		
	if( !mapp(adv_armor_prop=query("adv_props"))) adv_armor_prop=([]);

	owner->set_temp("armor/" + type, this_object());
	apply = keys(armor_prop);
	adv_apply=keys(adv_armor_prop);
	applied_prop = owner->query_temp("apply");
	if( !mapp(applied_prop) ) applied_prop = ([]);
	for(int i = 0; i<sizeof(apply); i++)
		if( undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] = armor_prop[apply[i]];
		else
			applied_prop[apply[i]] += armor_prop[apply[i]];
	for(int i = 0; i<sizeof(adv_apply); i++)
		if( undefinedp(applied_prop[adv_apply[i]]) )
			applied_prop[adv_apply[i]] = adv_armor_prop[adv_apply[i]];
		else
			applied_prop[adv_apply[i]] += adv_armor_prop[adv_apply[i]];
	owner->set_temp("apply", applied_prop);
	add_additional_prop(owner);
	set("equipped", "worn");
	return 1;
}

int wield()
{
	object owner, old_weapon;
	mapping weapon_prop,adv_weapon_prop,equips;
	string *apply, *adv_apply;
	int flag;
	string file;

	// Only character object can wear armors.
	if( !(owner = environment())->is_character() ) return 0;

        file=base_name(this_object());
        file=file+"#"+sprintf("%d",query("unique_id"));
	
	if( userp(owner) )
	if( !mapp(equips=owner->query("adv_equips")) || !arrayp(equips[file]) )
        {
                destruct(this_object());
                tell_object(owner,"这不是你的东西。\n");
        	return 0;
	}


	// If already wielded, just recognize it.
	if( query("equipped") ) return 1;

	// Check if we have "weapon_prop" defined.
	if( !mapp(weapon_prop = query("weapon_prop")) )
		return notify_fail("你只能装备可当作武器的东西。\n");
	if( !mapp(adv_weapon_prop = query("adv_props")) )  adv_weapon_prop=([]);

	flag = query("flag");

	if( flag & TWO_HANDED ) {
		if( owner->query_temp("weapon")
		||	owner->query_temp("secondary_weapon")
		||	owner->query_temp("armor/shield") )
			return notify_fail("你必须空出双手才能装备双手武器。\n");
		owner->set_temp("weapon", this_object());
	} else {

		// If we are are using any weapon?
		if( !(old_weapon = owner->query_temp("weapon")) )
			owner->set_temp("weapon", this_object());

		else // If we still have a free hand? 
		if( !owner->query_temp("secondary_weapon")
		&&	!owner->query_temp("armor/shield") ) {

			// If we can wield this as secondary weapon?
			if(flag & SECONDARY) {
				owner->set_temp("secondary_weapon", this_object());

			// If we can switch our old weapon to secondary weapon ?
			} else if( (int)old_weapon->query("flag") & SECONDARY ) {
				old_weapon->unequip();
				owner->set_temp("weapon", this_object());
				old_weapon->wield();

			// We need unwield our old weapon before we can use this one.
			} else
				return notify_fail("你必须先放下你目前装备的武器。\n");

		// We have both hands wearing something.
		} else
			return notify_fail("你必须空出一只手来使用武器。\n");
	}

	apply = keys(weapon_prop);
	for(int i = 0; i<sizeof(apply); i++)
		owner->add_temp("apply/" + apply[i], weapon_prop[apply[i]]);
	
	adv_apply=keys(adv_weapon_prop);
	for(int i = 0; i<sizeof(adv_apply); i++)
		owner->add_temp("apply/" + adv_apply[i], adv_weapon_prop[adv_apply[i]]);


	owner->reset_action();
	add_additional_prop(owner);
	set("equipped", "wielded");
	return 1;
}

int unequip()
{
	object owner;
	mapping prop, applied_prop, adv_prop;
	string *apply,*adv_apply, equipped;

	if( !(owner = environment())->is_character() ) return 0;

	if( !stringp(equipped = query("equipped")) )
		return notify_fail("你目前并没有装备这样东西。\n");

	if( equipped=="wielded" ) {
		if( (object)owner->query_temp("weapon") == this_object() )
			owner->delete_temp("weapon");
		else if( (object)owner->query_temp("secondary_weapon") == this_object() )
			owner->delete_temp("secondary_weapon");
		prop = query("weapon_prop");
		adv_prop=query("adv_props");
		owner->reset_action();
	} else if( equipped=="worn" ) {
		owner->delete_temp("armor/" + query("armor_type") );
		prop = query("armor_prop");
		adv_prop=query("adv_props");
	}

	apply = keys(prop);
	applied_prop = owner->query_temp("apply");
	for(int i = 0; i<sizeof(apply); i++)
		// To support array apply, we cannot add_temp() here.
		if( !undefinedp(applied_prop[apply[i]]) )
			applied_prop[apply[i]] -= prop[apply[i]];

	if(sizeof(adv_prop)) 
	{
		adv_apply = keys(adv_prop);
		for(int i = 0; i<sizeof(adv_apply); i++)
			if( !undefinedp(applied_prop[adv_apply[i]]))
				applied_prop[adv_apply[i]] -= adv_prop[adv_apply[i]];
	}
			
	remove_additional_prop(owner);
	delete("equipped");
	return 1;
}

void owner_is_killed(object killer)
{
//        object owner;
	
	if(!(query("adv_props"))) return;
	
       	//CHANNEL_D->do_channel(this_object(),"sys","杀人者是"+killer->query("name")+"。\n");	
        if( !killer )
        {
        	destruct(this_object());
        	return;
        }
        if(!userp(environment())) 
       	{
       		CHANNEL_D->do_channel(this_object(),"sys","被杀者"+environment()->query("name")+"。\n");	
       		tell_room(environment(killer),
       		CYN+query("name")+CYN"刹那间化作一股青烟，笼罩住"+killer->query("name")+CYN"全身，\n"NOR);
       		if(sizeof(killer->query("adv_equips"))<=ADV_EQUIP_LIMITED) 
       		{
       			tell_room(environment(killer),CYN"过了不久又慢慢消失不见。\n"NOR);
       			move(killer);
       		}
       		else 
       		{
       			tell_room(environment(killer),"终于，长啸一声冲天而去。"NOR);
       			destruct(this_object());
       		}
       		return;
       	}
	if(query("equipped"))
	{
		tell_room(environment(killer),
        	BLU+query("name")+BLU"哀鸣一声，化作一道青烟，盘旋在"+environment()->query("name")+BLU"上空，\n"
        	"久久不肯离去．．．．．．\n"
        	"终于，又长啸一声冲天而去。"NOR);
		detach();
	}
       else destruct(this_object());
       return;
}

int random_level()
{
	int level,random_num;
	random_num=random(1000);
	if(random_num<=400) level=0;
	else if(random_num<=600) level=1;
	else if(random_num<=800) level=2;
	else if(random_num<=900) level=3;
	else if(random_num<=950) level=4;
	else if(random_num<=990) level=5;
	else if(random_num<=998) level=6;
	else level=7;
	set("level",level);
	return level;
}

int random_value(int level,int basenum)
{
	//CHANNEL_D->do_channel(this_object(),"sys","level:"+sprintf("%d",level));
	if(level==0) return basenum+random(basenum);
	else if(level==1) return basenum*2+random(basenum*2);
	else if(level==2) return basenum*3+random(basenum*2);
	else if(level==3) return basenum*4+random(basenum*2);
	else if(level==4) return basenum*5+random(basenum*2);
	else if(level==5) return basenum*6+random(basenum*3);
	else if(level==6) return basenum*16+random(basenum*16);
	else if(level==7) return basenum*32+random(basenum*32);
	else return basenum;
}

int level_limited(int flag,int basenum,int level)
{
	if(!flag)
	{
		if(level==0) return basenum;
		else if(level==1) return basenum*2;
		else if(level==2) return basenum*3;
		else if(level==3) return basenum*4;
		else if(level==4) return basenum*5;
		else if(level==5) return basenum*6;
		else if(level==6) return basenum*16;
		else if(level==7) return basenum*32;
		else return basenum;
	}
	else
	{
		if(level==0) return basenum+basenum;
		else if(level==1) return basenum*2+basenum*2;
		else if(level==2) return basenum*3+basenum*2;
		else if(level==3) return basenum*4+basenum*2;
		else if(level==4) return basenum*5+basenum*2;
		else if(level==5) return basenum*6+basenum*3;
		else if(level==6) return basenum*16+basenum*16;
		else if(level==7) return basenum*32+basenum*32;
		else return basenum;
	}
}


varargs void adv_random_name(string *name1,string *name2,string *name3,string *equip_color,mapping etoc,int level)
{
	string *ename,c_name,e_name,c_name1,c_name2,c_name3;
	string color;
	ename=({name1[random(sizeof(name1))]});
	ename+=({name2[random(sizeof(name2))]});
	ename+=({name3[random(sizeof(name3))]});
	if(level>=0)
	{
		if(level<=7)
		{
			color=equip_color[level];
			set("level",level);
		}
		else
		{
			color=equip_color[0];
			set("level",0);
		}
	}
	else color=equip_color[random_level()];
	set("value", (1+query("level"))*50000);
	if(ename[0]=="") {c_name1="";e_name="";}
	else {c_name1=etoc[ename[0]];e_name=ename[0]+" ";}
	c_name2=etoc[ename[1]];e_name+=ename[1];
	if(ename[2]=="") {c_name3="";e_name+="";}
	else {c_name3=etoc[ename[2]];e_name+=" of "+ename[2];}
	c_name=c_name3+c_name1+color+c_name2+NOR;
	set_name(c_name, ({e_name, ename[1] }) );
	set("ename",ename);
	return;
}

void adv_random_prop(mapping advanced_prop)
{
	string *props=({});
	string prop;
	int prop_num,i,level;
	props=keys(advanced_prop);
	prop_num=1+random(sizeof(props)-1);
	level=query("level");
	delete("adv_props");
	for(i=0;i<prop_num;i++)
	{
		prop=props[random(sizeof(props))];
		//CHANNEL_D->do_channel(this_object(),"sys","level:"+sprintf("%d",level)+","+prop+":"+sprintf("%d",advanced_prop[prop]));
		set("adv_props/"+prop,random_value(level,advanced_prop[prop]));
		props-=({prop});
	}
	return;
}


int adv_reload_props(mixed props,string *equip_color,mapping etoc,mapping advanced_prop)
{
	int bug,i,cur_value,high_value,low_value;
	string *ename,c_name,e_name,c_name1,c_name2,c_name3;
	string color,*prop_keys;
	set("attached",1);
	set("unique_id",props[0]);
	if(!query("random")) return 0;	//不是随机name的super equip
	set("level",props[2]);
	ename=props[1];
	color=equip_color[props[2]];
	//CHANNEL_D->do_channel(this_object(),"sys","name:"+ename[0]+"\n");	
	//CHANNEL_D->do_channel(this_object(),"sys","name:"+ename[1]+"\n");	
	//CHANNEL_D->do_channel(this_object(),"sys","name:"+ename[2]+"\n");	
	
	if(ename[0]=="") {c_name1="";e_name="";}
	else {c_name1=etoc[ename[0]];e_name=ename[0]+" ";}
	c_name2=etoc[ename[1]];e_name+=ename[1];
	if(ename[2]=="") {c_name3="";e_name+="";}
	else {c_name3=etoc[ename[2]];e_name+=" of "+ename[2];}
	c_name=c_name3+c_name1+color+c_name2+NOR;
	set_name(c_name, ({e_name, ename[1] }) );
	//
	
	prop_keys=keys(props[3]);
	bug=0;
	for(i=0;i<sizeof(prop_keys);i++)
	{
		cur_value=props[3][prop_keys[i]];
		high_value=level_limited(1,advanced_prop[prop_keys[i]],props[2]);
		low_value=level_limited(0,advanced_prop[prop_keys[i]],props[2]);
		if(cur_value>high_value)
		{
			bug=1;
			props[3][prop_keys[i]]=high_value;
		}
		else if(cur_value<low_value)
		{
			bug=1;
			props[3][prop_keys[i]]=(low_value+high_value)/2;
		}
	}
	
	// check equip bug
	set("value", (1+query("level"))*50000);
	set("adv_props",props[3]);
	
	return bug;
}

void add_additional_prop(object who)
{
	int added_kee,added_sen,added_gin;
	if(added_kee=query("adv_props/add_max_kee")) {
		who->add("eff_kee",added_kee*10);
		who->add("max_kee",added_kee*10);
		}
	if(added_sen=query("adv_props/add_max_sen")) {
		who->add("eff_sen",added_sen*10);
		who->add("max_sen",added_sen*10);
		}
	if(added_gin=query("adv_props/add_max_gin")) {
		who->add("eff_gin",added_gin*10);
		who->add("max_gin",added_gin*10);
		}
}

void remove_additional_prop(object who)
{
	int added_kee,added_sen,added_gin;
	if(added_kee=query("adv_props/add_max_kee")) {
		who->add("eff_kee",-added_kee*10);
		who->add("max_kee",-added_kee*10);
		}
	if(added_sen=query("adv_props/add_max_sen")) {
		who->add("eff_sen",-added_sen*10);
		who->add("max_sen",-added_sen*10);
		}
	if(added_gin=query("adv_props/add_max_gin")) {
		who->add("eff_gin",-added_gin*10);
		who->add("max_gin",-added_gin*10);
		}

}
