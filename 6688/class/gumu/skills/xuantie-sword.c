// xuantie-sword 玄铁剑法
//by masterall

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      
        "action" : "$N左手抽出背负的$w，顺手挥出，“噗”的一声，响声又沉又闷，便如木棍击打败革。",
        "force" : 200,
        "parry" : 10,
        "attack": 20,
        "damage" : 120,
        "unparryable" : 10,
        "lvl" : 30,
        "damage_type" : "瘀伤"
]),
([      
        "action" : "$N$w斜挑，$w剑尖抖处，已将$n的$l黏住，$n只觉得一股惊涛骇浪般的内力奔袭而来。",
        "force" : 250,
        "parry" : 10,
        "attack": 25,
        "damage" : 150,
        "unparrydodge" : 10,
        "lvl" : 50,
        "damage_type" : "瘀伤"
]),
([      
        "action" : "$N撒手送剑，$w向$n直撞了过去。$n想不到来势竟是如此猛烈，眼见就要闪避不及。",
        "force" : 300,
        "parry" : 15,
        "attack": 40,
        "damage" : 100,
        "unparrydodge" : 10,
        "unparryable" :  10,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N$w当胸疾刺，转瞬间，$n尚未击到$N头顶，剑头距$n的$l已不到半尺。",
        "force" : 250,
        "parry" : 20,
        "attack": 30,
        "damage" : 150,
        "unparryable" :  20,
        "lvl" : 150,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N$w刺出，嗒的一声轻响，已抵在$n的$l上，霎时之间两人僵持不动，
$N却用袖子出其不意的猛拂$n面门。",
        "force" : 300,
        "parry" : 20,
        "attack": 40,
        "damage" : 50,
        "unparryable" : 30,
        "unparryable" : 30,
        "lvl" : 180,
        "damage_type" : "瘀伤"
]),
([      
        "action" : "$N$w向前疾刺，或击前胸，或削腰腹，破空竟无办点风声。",
        "force" : 160,
        "parry" : 30,
        "attack": 30,
        "damage" : 180,
        "lvl" : 199,
        "unparryable" : 10,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N向$n背心疾刺数剑，一时间却又雷鸣电闪，招招势若暴风骤雨。",
        "force" : 200,
        "parry" : 30,
        "attack": 35,
        "damage" : 200,
        "lvl" : 219,
        "undodgeable" : 30,
        "damage_type" : "瘀伤"
]),
});

string *parry_msg = ({
        "待$N的$w攻至，起脚下落，已将$w踏在足底。。\n",
        "$n全身劲力都贯到了左臂之上，剑尖颤动，当当当三响，挑开了$N的$w。\n",
        "$n的$v一送即收，回剑向後，当的一响，已将背後袭来的$w震飞。\n",
        "$n的$v却似使得颇为涩滞。但不论$N如何变招，始终欺不近$n三步之内\n",
        "$n见$N的$w攻至，竟不避让，$v抖动，霎时兵刃相触，声如龙吟。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

int valid_learn(object me)
{
//            if(me->query("str")<50)
//                          return notify_fail("你的臂力太低，无法领会玄铁剑法的精义。");
            if(me->query_skill("jiuyin-shengong",1) < 180)
                return notify_fail("你的「九阴神功」修为太低，无法领会玄铁剑法的奥秘。\n");

        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("xuantie-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object ob;
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if( (int)me->query("kee") < 60
        ||      (int)me->query("force") < 60 )
                return notify_fail("你的内力或气不够，没有办法练习玄铁剑法。\n");
        me->receive_damage("kee", 50);
        me->add("force", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xuantie-sword/" + action;
}

int attack_ratio() {
        return 30;
}

int query_sheng_ke(string skill) 
{
      if(skill == "wuxinglun" ) return 300;
   if(skill == "snowwhip") return 100;
        return 300;
}



/*
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "jiuyin-shengong" )
        return( ([ 
                "force":"jiuyin-shengong",     
        ]) );
        else
        return( ([ 
                "force":"yunu-xinfa",   
        ]) );

}

*/
mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "yunu-xinfa" ){
        return( ([ 
                "force":"yunu-xinfa",     
        ]) );
        }else if( this_player()->query_skill_mapped("force") == "jiuyin-shengong" ){
        return( ([ 
                "force":"jiuyin-shengong",   
        ]) );
        }else{
        return( ([ 
                "force":"xiantian-gong",   
        ]) );
        }

}

mapping level_req(int level) 
{

        return( ([
                "sword":200,    
                "force":200,
        ]) );
}

int effective_level() {
        return 20;
}

int query_faith_req(int skill) 
{
        return 10*skill+1;
}

void hit_ob(object me,object victim,int damage_bonus)
{
        object weap;
        int    wap,wdp;
     //   string weap_name;

        if(victim == me) return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = me->query_str()*3+me->query_skill("force");

                wdp = (int)victim->query("str")+victim->query_skill("force");
        if( victim->query("id") == "long xiang" )  wap= wap/10;
        if( victim->query("id") == "buzhi huowu" )  wap= wap/10;

                if(  random(wap+wdp) > wdp )
                {
                        message_vision(HIW"只听见「叮」地一声爆响，$N手中的" + weap->name()
                                +HIW "再也拿捏不住，脱手飞出！\n"NOR,victim,me);
                        weap->unequip();
                        weap->move(environment(victim));
                        victim->reset_action();
                }
                                
        }
}


int post_parry_attack(object me, object victim)
{
        int level;
        object weapon1, weapon2;
        string name1, name2;

        level = me->query_skill("xuantie-sword", 1);

        if (level < 220 )       return 0;

        if( me->query_skill_mapped("parry") != "xuantie-sword" )  return 0;

        if( !me->query_temp("weapon") )  return 0;

        weapon1 = me->query_temp("weapon");
        name1 = weapon1->query("name");


        if( objectp(weapon2 = victim->query_temp("weapon")) )
                name2 = weapon2->query("name");
        else    name2 = "手臂";

        if( victim->query("force") < victim->query("force_factor")
          || victim->query("force_factor") == 0)
                return 0;

        message_vision(HIY"$N的" + name2 + HIY"“叮”的一声撞上了$n的" + name1 + HIY"，四溅的火星迸得缤纷乱飞！\n"NOR, victim, me);

                if( random(victim->query("force") + me->query("force")) > victim->query("force")){
                message_vision(HIW"$N感到$n的内力如海潮般从四面八方齐至，此声势比之雷震电轰更是厉害！\n$N已经渐渐感到真气略有不纯，攻守交变之间也颇有滞涩。\n\n"NOR, victim, me);
                victim->add("force", -3*me->query("force_factor"));
                victim->start_busy(1);
                }else{
                message_vision(HIG"$N迎波击刺！" + name2 + HIG"上所发劲风和$n斗了个旗鼓相当！！\n"NOR, victim, me);
                victim->add("force", -1*victim->query("force_factor"));
                me->add("force", -1*me->query("force_factor"));
                }

        return 1;
}

int post_parry_defense(object me, object victim)
{
        return post_parry_attack(me, victim);
}
