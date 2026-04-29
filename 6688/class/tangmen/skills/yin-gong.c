// 阴功
// force/claw/parry/dodge
// by masterall

#include <ansi.h>

inherit FORCE;
//inherit SKILL;

mapping *action = ({
([      
        "action" : HIB"$N淡淡的一笑，脸上有说不出的诡异，就在$n心头大惑之时，\n"
                        "一双力爪闪电般攻向$n的咽喉！"NOR,
        "force" :   200,
        "dodge" :   20,
        "parry" :   20,
        "attack":   20,
        "damage":   100,
        "lvl"   :   20,
        "damage_type" : "抓伤"
]),
([      "action": HIB"$N轻喝一声，鬼魅般的在$n身旁出现，迎上$n，一拳击出，\n"
                     "$n竟吓得完全没有招架闪避之力！"NOR,
        "force" :   300,
        "dodge" :   30,
        "parry" :   30,
        "attack":   30,
        "damage":   150,
        "lvl"   :   100,
        "damage_type":  "瘀伤"
]),                                
([      
        "action": HIB"$N用双尖针般的笑眼看着$n，$n的身子不由得一阵发紧，\n"
                "浑身哆嗦了一下，眼前一道炫芒，$N的利爪已经戳向了$n的双目！"NOR,
        "dodge":                35,
        "force":                400,
        "parry":                35,
        "attack":               35,
        "damage":               200,
        "lvl"   : 150,
        "damage_type":  "抓伤"
]),

([      
        "action" : HIB"$N腰肢如舞姬般妩媚的扭动了起来，让$n看了不知道是痴迷还是想呕吐，\n"
                      "然而$n想扼住自己喉咙倾泄之时，却发现$N的双爪已然先一步袭至！"NOR,
        "damage" :   250,
        "dodge" :    40,
        "parry" :    40,
        "attack":    40,
        "force":     500,
        "lvl"   :    200,
        "unparryable":  30,
        "damage_type" : "抓伤"
]),             

});

string *parry_msg = ({
        "$n诡异的一笑，右手轻拂$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右手虚幌，左手「摘星扫月」，逼得$N后退三步。\n",
        "$n双爪齐出，使出一招「沧海横流」，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int attack_ratio()
{       
        return 100;
}

string *dodge_msg = ({
        "$n双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
        "$n伏下身去，在半空中一转，已落到几丈远的地方。\n",
        "$n一转身间，四面八方飘动着无数个$n的身影，令$N手无足措。\n",
        "$n纵身一跃，飘至半空 。转眼间便绕到了$N的身后。\n",
});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_enable(string usage) { return (usage == "force" || usage == "claw" || usage == "parry" || usage == "dodge"|| usage == "move"); }


int valid_learn(object me)
{
        int nf;
        nf = (int)me->query_skill("force", 1);

        if ( nf < 250)
                return notify_fail("你的内功还不够深厚，无法领会阴功的劲力。\n");
        if( me->query("gender") != "无性") {
                return notify_fail("阴功不是一般人可以练的! \n");
        }

        return 1;
}

int practice_skill(object me)
{
        if( me->query("force") < 50) return notify_fail("你的内力不够，无法练习阴功！\n");
        if( (int) me->query_skill("yin-gong", 1) >= 380)
                return notify_fail("你的阴功已经不能再练了。\n");
        if( (int)me->query("kee") < 60 )
                return notify_fail("你的气不够，没有办法练习阴功。\n");
        me->receive_damage("kee", 50);
        me->add("force", -30);
        return 1;
}


string exert_function_file(string func)
{
        return __DIR__"yin-gong/" + func;

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int poison;
        poison = victim->query_condition("tm_poison");
        if( me->query_temp("weapon") ) return 0;
        if( damage_bonus < 100 ) return 0;
 
        if( random(damage_bonus) > victim->query_str() ) {
                victim->apply_condition("tm_poison",poison+10+random(10));
                victim->add("eff_gin",-1 * (damage_bonus - 100) / 4 );
                victim->add("eff_kee",-1 * (damage_bonus - 100) / 4 );
                switch(random(3)) {
                        case 0: return HIR "$n听到「咔嚓」一声爆响，竟似是自己喉咙破碎的声音！\n" NOR;
                        case 1: return HIB "$n打了个哆嗦，好像自己的经脉被一股阴柔的气劲截断了！\n" NOR;
                        case 2: return HIG "$n觉得伤口处耗无疼痛，只是隐隐的有些发麻！！\n" NOR;
                }
        }
} 

string query_force_type() {

        return "阴邪内功";

}

int query_faith_req(int skill) {
        return 10*skill+100;
}

int effective_level() { return 15;}

mapping level_req(int level) {

        return( ([
                "force":250,       
        ]) );
}

