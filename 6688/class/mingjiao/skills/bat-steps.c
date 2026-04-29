// 青蝠身法

inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
         HIC"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n"NOR,
         HIC"可是$n不紧不慢往右走了一步，躲过了$N这一招。\n"NOR ,
         HIC"但是$n身形飘忽，轻轻一纵，早已避开。\n"NOR ,
         HIC"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n"NOR ,
         HIC"可是$n侧身一让，$N这一招扑了个空。\n"NOR ,
         HIC"却见$n足不点地，往旁窜开数尺，躲了开去。\n"NOR ,
         HIC"$n身形微晃，有惊无险地避开了$N这一招。\n"NOR ,
         HIC"$n看似无心地信手一拂，肩头微侧,堪堪避过了$N这一招。\n"NOR 
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me)
{
        if ( me->query("gender") != "女性"  )
                return notify_fail("青蝠身法走的是阴柔的路子，你的体质不适合修习这门功夫。\n");
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的体力太差了，练不了青蝠身法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

/*
mapping enable_req() {

        return( ([ 
                "force":"moni-xinfa",        
        ]) );

}
*/

int effective_level() {
        return 18;
}

int query_faith_req(int skill) {
        return 10+skill*10;

}

