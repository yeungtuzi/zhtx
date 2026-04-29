// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int af,mavf;
        int damage;

        if(userp(me))//add by emote,for npc not decrease force.04/01/2000
        me->add("force", - factor );
        damage = factor
                + (int)me->query("max_force")/20
                + (int)me->query("force")/40
                - (int)victim->query("max_force")/50
                - (int)victim->query("force")/100
                - (int)victim->query("force_factor")/2;

        if( damage < 0 ) {
                if( !me->query_temp("weapon")
                &&      random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
                        damage = - damage;
                        me->receive_damage( "kee", damage * 2 );
                        me->receive_wound( "kee", damage );
                        if( damage < 10 ) return "$N受到$n的内力反震，闷哼一声。\n";
                        else if( damage < 20 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
                        else if( damage < 40 ) return "$N被$N以内力一震，胸口有如受到一记重□，连退了五六步！\n";
                        else return "$N被$n的内力一震，眼前一黑，身子向後飞出丈许\！！\n";
                }
                if( damage_bonus + damage < 0 ) return - damage_bonus;
                return damage;
        }
        mavf = victim->query("armor_vs_force")/10;
        af = mavf + victim->query_temp("apply/armor_vs_force")/2;
        if( af > 500 ) af = 500;
        damage -= af;
        //faint,在这个地方就开始减,狠了点啊
        if( damage_bonus + damage < 0 ) return - damage_bonus;
/*
        if( random(me->query_skill("force")) < damage )
*/
                return damage;
}

