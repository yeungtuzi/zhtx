// beimin-shengong.c 北冥神功
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	return 1;
}

int practice_skill(object me)
{
    return notify_fail("北冥神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"beiming-shengong/" + func;
}

string query_force_type()       {return "北冥神功";}

int query_faith_req(int skill) {return 100+skill*5;}

void skill_improved(object me)
{
	int i;

	i = me->query_skill("beiming-shengong", 1);
	if( i == 1 ){
		tell_object(me, HIY"师父对你说：“本派弟子，功在人在，功亡人亡，切记切记！”\n"NOR);
		return;
	}

	if( me->query_skill("huagong-dafa",1) > 100 ){
		if( i > 94 && i < 100 ){
			tell_object(me, HIY"你似有所悟，可是一时又说不上来。\n"NOR);
			return;
		}
		if( i == 100 ){
			tell_object(me, HIG"你听了师父的讲解，以前学化功大法时的种种困惑和疑窦一刹那间全部迎刃而解，你的北冥神功进步了！"NOR);
			me->set_skill("beiming-shengong", me->query_skill("huagong-dafa", 1));
			return;
		}
	}
	return;
}
int post_parry_attack(object me, object victim)
{
        int level;
        object weapon1, weapon2;
        string name1, name2;

        level = me->query_skill("beiming-shengong", 1);

        if (level < 182 )       return 0;

        if( objectp(weapon1 = me->query_temp("weapon")) )
                name1 = weapon1->query("name");
        else    name1 = "手臂";


        if( objectp(weapon2 = victim->query_temp("weapon")) )
                name2 = weapon2->query("name");
        else    name2 = "手臂";

        if( victim->query("force") < victim->query("force_factor")
          || victim->query("force_factor") == 0)
                return 0;

        message_vision(HIY"$N的" + name2 + HIY"和$n的" + name1 + HIY"一接近, 立时感到全身一阵剧震, 一股真气不由自主地自" + name2 + HIY"直涌向$n.\n", victim, me);
        if( random(10) == 0 )
                message_vision(HIY"$N的北冥神功好生厉害, 居然可以凌空吸取内力!\n"NOR, me);

        victim->add("force", -victim->query("force_factor"));
//        victim->start_busy(1);
        me->add("force", victim->query("force_factor"));

        if ( me->query("force") > 2 * me->query("max_force") )
                me->set("force", 2 * me->query("max_force"));

        return 1;
}

int post_parry_defense(object me, object victim)
{
        return post_parry_attack(me, victim);
}
