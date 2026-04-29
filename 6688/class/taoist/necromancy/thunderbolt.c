// thunder-bolt.c
// from fy2

#include <ansi.h>

inherit SSERVER;

int do_cast(object);

int thunderspell(object me, object obj)
{
	int	spi, kar, kee, damage, spells;

	message_vision(YEL "\n一个闪电向$N的头上打来，\n" NOR, obj);
	obj->receive_damage("sen", 0, me);
	spells = me->query_skill("spells");
	if(obj->is_ghost()==1) {
		message_vision(RED "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
		obj->die();
		return 1;
	}
	if(obj->is_zombie()==1) {
		message_vision(RED "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
		obj->die();
		return 1;
	}  

	if(obj->query("race")=="野兽") {
		kar = obj->query("kar");
		spi = obj->query("spi");
		damage = (31 - spi)*(spells/4)*(random(31-kar)+1)+100;
		if(damage <= 20) damage = 0;
		if(damage != 0) {
			message_vision(RED "正打在了$N的头上！\n" NOR, obj);
			obj->receive_damage("kee", damage, me);
	 		COMBAT_D->report_status(me,obj);
			if( !obj->is_fighting(me) ) {
                		if( living(obj) ) {
                        		if( userp(obj) ) 
						obj->fight_ob(me);
					else
						obj->kill_ob(me);
                		}
                		me->kill_ob(obj);
        		}
		} else 
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
		return 1;
	}
	//kar = obj->query("kar");
	//spi = obj->query("spi");
	//damage = (31 - spi)*(spells/10)*(random(30-kar)+1);
	 damage =  (int)me->query("mana")/40+(int)me->query("max_mana") / 20 + ((int)me->query("eff_sen") / 10);
         damage -= (int)obj->query("mana")/40+(int)obj->query("max_mana") / 20 + (int)obj->query("eff_sen") / 10;
	spi = me->query_skill("spells") + me->query("spi") - obj->query_skill("spells") - obj->query_spi();
	spi = spi * spi * spi /40000;
	damage += spi;
	if( !userp(obj) ) damage *= 2;
	damage = damage/2 + random(damage/2);

	if (damage < 0) damage = 0;
	//加入对灵界生物的杀伤力，消除其隐识的作用
	if( !wiz_level(obj) && obj->query("env/invisibility") &&!raw_wiz_level(obj))
	{
		message_vision(RED "$N一声惨嚎，喷出一口鲜血，现出了原身！\n" NOR,obj);
		obj->delete("env/invisibility");
		obj->receive_wound("kee",damage,me);
 		COMBAT_D->report_status(me,obj);
		return 1;
	}
	//if(damage > 20) damage = 20;           
	//对普通人类最大伤20气的下限
	if(damage != 0 && random(kar) < 20) {
		message_vision(RED "正打在了$N的头上！\n" NOR, obj);
		obj->receive_damage("kee", damage, me);
 		COMBAT_D->report_status(me,obj);
		if( !obj->is_fighting(me) ) {
               		if( living(obj) ) {
                       		if( userp(obj) ) 
					obj->fight_ob(me);
				else
					obj->kill_ob(me);
               		}
               		me->kill_ob(obj);
       		}
	} else 
			message_vision(RED "但被$N躲过了！\n" NOR, obj);
	return 1;
	
}
int cast(object me)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;

	if((int)me->query_skill("spells") < 180 )
		return notify_fail("你的法术不够高！\n");

	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的体力不够！\n");

	if((int)me->query("sen") < 80 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -100);
	me->receive_damage("sen", 50);

	msg = YEL "$N脚踩天罡步，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
        message_vision(msg, me);
	me->set_temp("prepare_thunderbolt",5);
        seteuid(ROOT_UID);
        me->start_busy(
                bind((: call_other, __FILE__, "do_prepare", me :), me),
                bind((: call_other, __FILE__, "interrupt_prepare" :), me) );
        //        0 );
        return 1;
}

int interrupt_prepare(object me)
{
	return 1;
}

int do_prepare(object me)
{
	int left_busy;
        
        me->add_temp("prepare_thunderbolt",-1);
        left_busy = me->query_temp("prepare_thunderbolt");
	if( left_busy == 1)
	{
		me->delete_temp("prepare_thunderbolt");
		do_cast(me);
	}
	else if( left_busy > 1 )
		message_vision(HIY"$N脚下踩着八卦方位,口中咒语念个不停.\n"NOR,me);
	else
	{
		me->delete_temp("prepare_thunderbolt");
		return 0;
	}
	
	return 1;
}

void do_cast(object me)
{
	string msg;
	object env,*inv;
	int i;

	msg =  RED "猛地双手一挥，天上打下无数闪电！\n\n" NOR;
	message_vision(msg, me);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		// 防止采用这个pk,只对和自己战斗中的玩家有效 yeung
//		if( userp(inv[i]) && !me->is_fighting(inv[i]) ) continue;
		thunderspell(me, inv[i]);
        }
}

