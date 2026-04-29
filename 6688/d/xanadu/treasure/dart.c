// yeung
// all rights reserved.

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

string *my_poison = ({
	"tm_poison",
	"rose_poison",
	"snake_poison",
	"ninemoonpoison",
	"iceshock",
        "super_poisons",
	});

void attack_ob(object me,object victim,int ap);

void create()
{
        set_name(HIY"飞去来兮"NOR, ({ "dart" }) );
	set("no_decrease",1);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "这是一种十分精巧的玩具，可在扔出去后自动返回主人手里。\n");
                set("value", 0);
		set("base_unit","枚");
               	set("material", "steel");
		set("unit","枚");
        }
	set("rigidity",500000);
	set("weapon_prop/attack",50);
	set("poison/type",my_poison[random(sizeof(my_poison))]);
	set("poison/amount",1000+random(2000));
        set_amount(1);
        init_throwing(185);
        setup();
}
                                       
int init()
{
	add_action("do_throw","throw");
}	         

int do_throw(string args)
{
	object *inv,me;
	int i,ap,skill_lev;

	if( !query("equipped") )
		return 0;

	me = this_player();
        inv = all_inventory(environment(me));

	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if( me->query("force") < 200 )
		return notify_fail("你的内力不足！\n");
	
	message_vision(HIY"$N将"+query("name")+HIY"高高抛起，随即运足内力将"+query("name")+HIY"轻飘飘地送了出去。\n"NOR,me);
	me->add("force",-100);

	skill_lev = me->query_skill("throwing");
	ap = me->query("combat_exp")+skill_lev*skill_lev/9*skill_lev;
	if(ap<1)
		ap = 1;
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
                attack_ob(me, inv[i],ap);
        }
	
	message_vision("\n\n"+HIY+query("name")+HIY"在空中转了个弯，又回转到了$N的手中。\n"NOR,me);	

        me->start_busy(5);
        return 1;

}

void attack_ob(object me,object victim,int ap)
{
	int dp,skill_lev,result;
	string name,msg,poison;

	result = 0;
	name = query("name"); 

	msg = "\n\n"+name+HIR"发出呜呜的破空声，循一道怪异的轨迹向$N划来！\n"NOR;
	skill_lev = victim->query_skill("dodge");
	dp = living(victim)?(victim->query("combat_exp")/2 + skill_lev*skill_lev/81*skill_lev):1;

	if( random(ap+dp)<dp )
		msg += "但是，$N轻轻一纵，"+name+"与$N擦身而过！\n";		
        else
	{
		skill_lev = victim->query_skill("parry");
		dp = living(victim)?(victim->query("combat_exp")/2 + skill_lev*skill_lev/81*skill_lev):1;
		if( random(ap+dp) < dp )
			msg += "只听“咣”地一声大响，$N将"+name+"磕得直飞了出去。\n";	
        	else
		{
			msg += HIR"结果只听$N一声惨嚎，在措手不及之下被"+name+HIR"划得左肩血肉横飞！\n"NOR;
			result = 1;
		}
	}                 
		
	message_vision(msg,victim);
        if(result)
	{
		poison = query("poison/type");
		victim->receive_damage("kee",ap/30000+random(ap/10000)+me->query("force_factor"),me);
		victim->receive_wound("kee",ap/90000+random(ap/30000)+me->query("force_factor"),me);
		if( query("poison/amount") > 0 )
		{
			victim->apply_condition(poison,10+random(10)+victim->query_condition(poison));
                        add("poison/amount",-10);
		}
		if( query("poison/amount") <= 0)
		{
			delete("poison");
			tell_object(me,name+"上面的毒质已经用完了。\n");
		}
		tell_object(victim,HIR"你感到伤口一阵麻木...\n"NOR);
		victim->start_busy(3);
		COMBAT_D->report_status(me,victim,1);
	}
	
	me->kill_ob(victim);	
	victim->kill_ob(me);
}
