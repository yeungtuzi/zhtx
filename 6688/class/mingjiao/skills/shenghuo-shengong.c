// shenghuolin.c
// Writed by yuer

// modified by yeung
// shenghuo-shengong的厉害招数必须配合qiankun-danuoyi才能用出来。

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action":"$N身形一晃，“啪”的一声，抓住$n的后领，远远掷了出去",
        "force" : 50,
        "dodge" : -10,
        "attack": 15,
        "damage": 40,
        "lvl" : 0,
        "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":"$N$w向$n咽喉点去，$w忽然尾端一弹，急点$n手腕",
        "force" : 50,
        "attack": 15,
        "dodge" : -10,
        "damage": 50,
        "lvl" : 10,
        "weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然连翻三个筋斗，白影一闪,有如一条白链，$w向$n重重击去",
        "force" : 60,
        "dodge" : 5,
        "attack": 15,
        "damage": 80,
        "lvl" : 25,
        "weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":"突然间$N向后摔出，$w从一个不可思议的角度电般急射向$n",
        "force" : 100,
       "dodge" : 5,
        "attack": 20,
        "damage": 100,
        "lvl" : 40,
        "weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$N身体急转，旋风般飞起两脚，$w乘虚刺向$n的小腹，端的是神妙无伦，不可思议",
        "force" : 160,
       "dodge" : 5,
        "attack": 25,
        "damage": 120,
        "lvl" : 120,
        "weapon" : "手指",
        "damage_type":  "刺伤"
]),

//下面几招必须有qiankun-danuoyi作parry配合才有可能用出来
//所以比较厉害。

([      "action":"$n攻向$N的$l，$N不退反进，忽然低头向$n撞来，攻了$n一个措手不及",
        "force" : 180,
        "dodge" : 5,
        "attack": 25,
        "damage": 130,
        "lvl" : 200,
        "weapon" : "左手",
        "damage_type":  "刺伤"
]),
([      "action":"$N跃身半空，忽然向$n头顶坐了下来，甚是怪异，竟以臀部攻人",
        "force" : 250,
        "dodge" : 5,
        "attack": 30,
        "damage": 140,
        "lvl" : 230,
        "weapon" : "",
        "damage_type":  "淤伤"
]),
([      "action":"$N剧斗之中忽然坐倒，双手从一个绝不可能的角度拿向$n双腿筑宾穴",
        "force" : 270,
        "dodge" : 5,
        "attack": 35,
        "damage": 150,
        "lvl" : 300,
        "weapon" : "",
        "damage_type":  "瘀伤"
]),
([      "action":"$N突然反身急速退向$n怀中，$n力未及发，$N$w已至",
        "force" : 280,
        "dodge" : 5,
        "attack": 40,
        "damage": 180,
        "lvl" : 350,
        "weapon" : "右掌",
        "damage_type":  "刺伤"
]),

});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "parry" || usage == "hand"; 
}

int valid_learn(object me)
{
        if( ((int)me->query_skill("fanwen", 1) + 20) < (int)me->query_skill("shenghuo-shengong", 1) && (int)me->query_skill("fanwen",1)<200)
                return notify_fail("你的梵文等级不够。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候太浅。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("shenghuo-shengong",1);

        if( me->query_skill_mapped("parry") == "qiankun-danuoyi" )
                level += (int) me->query_skill("qiankun-danuoyi",1);

        for(i = sizeof(action); i > 0; i--)
                        if(level > action[i-1]["lvl"])
                                return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40
        ||      (int)me->query("force") < 20 )
                return notify_fail("你的内力或气不够，没有办法练习圣火神功。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"shenghuo-shengong/" + action;
}

string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "jiuyang-shengong" )
        return( ([ 
                "force":"jiuyang-shengong",     
        ]) );
        else
        return( ([ 
                "force":"moni-xinfa",   
        ]) );

}

mapping level_req(int level) {

        return( ([
                "jiuyang-shengong":20,  
        ]) );
}
int attack_ratio() {
        return 80;
}

int query_faith_req(int skill) {
        return skill*6+3;
}

int query_ally(string skill,int amount)
{
        if( skill=="essence-sword" ) return 250;
        return 0;
}


mixed hit_ob(object me, object victim)
{
        mapping action;
        string  parry_skill,msg;
        int sh_lvl,exp,kar,intel,parry_lvl,att_lvl,force,damagea,damageb,damage1,damage2,force_fac,force_faca,eff_force;      
        action = victim->query("actions");
        sh_lvl = me->query_skill("jiuyang-shengong");
        parry_skill = me->query_skill_mapped("parry");
        parry_lvl = me->query_skill("qiankun-danuoyi");// 200lvl 挪移 query 出来的是100 
        att_lvl = me->query_skill("shenghuo-shengong");//这个也一样 
        force = me->query("max_force");
        kar = me->query("kar");
        intel = me->query("int");
        force_fac = me->query("force_factor");
        force_faca = victim->query("force_factor");
        eff_force = me->query("force");
        exp = me->query("combat_exp");
        damagea = random(action["damage"]*(parry_lvl-50)*kar*intel/20000)+random(force_fac/5+force/40+force_faca/4)+1;
        damageb = random(action["force"]*(parry_lvl-50)*kar*intel/10000)+random(force_fac/3+force/30+force_faca/2)+1;
        if(damagea>=damageb) {
                damage1 = damagea;
                damage2 = damageb;
        } else {
                damage1 = damageb;
                damage2 = damagea;
                }
        if(sh_lvl>95&&parry_skill == "qiankun-danuoyi"&&random(eff_force)>300&&att_lvl>95&&random(kar)>9&&random(intel)>29&&random(parry_lvl)>60&&force>2500&&parry_lvl>95) {
                msg = HIM "$N在战斗中突然悟到水火互济，阴阳相合的道理，\n将圣火神功和乾坤大挪移心法彻底融会贯通，达到从心所欲的境界。\n\n"NOR;
                if (damage1<500&&damage2<500) {
                    msg += HIY"$N看也不看$n,随手一震,$n如胸中大锤，呼吸为之一滞，向后踉跄出去，险些跌倒。\n\n"NOR ;
                    me->add("force",-150);
                    if(me->query("force")<=0) me->set("force",0);
                    victim->receive_damage("kee", damage1*7/10);
                    victim->receive_wound("kee", damage2*7/10);
                    me->start_busy(random(2)+1);
            } else {
                    msg += HIR "$N将$n的数道真气汇蓄起来，劈出一道狂烈无匹的气劲！\n\n"NOR;
                    msg += HIC "$n被这道狂澜击中，浑身经脉欲裂，狂喷鲜血，如同稻草一般被这股气劲抛飞出去！\n"NOR;
                    me->add("force",-300);
                    me->start_busy(random(3)+1);
                    if(me->query("force")<=0) me->set("force",0);
                    victim->receive_damage("kee", damage1*12/10);
                    victim->receive_wound("kee", damage2*12/10);
            } 
                    return msg;
                    
        } else {
        return 0;
        }
}


