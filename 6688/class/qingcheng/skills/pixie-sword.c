// pixie-sword.c 辟邪剑法
// Jay 4/5/96
// dao 5/2/98
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action":"突然之间，白影急幌，$N向后滑出丈余，立时又回到了原地",
        "force" : 30,
        "attack":15,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "白影急幌",
        "damage_type":  "刺伤"
]),
([      "action":"$N右手伸出，在$n手腕上迅速无比的一按，$n险些击中自己小腹",
        "force" : 40,
        "attack":15,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "自己小腹",
        "damage_type":  "刺伤"
]),
([      "action":"蓦地里$N猱身而上，蹿到$n的身后，又跃回原地",
        "force" : 50,
        "dodge" :10, 
        "attack":15,
        "damage": 50,
        "skill_name" : "猱身而上",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
        "dodge" :10,        
        "damage": 60,
        "force" : 50,
        "attack":15,
        "lvl" : 5,
        "skill_name" : "招法一变",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧",
        "dodge" :20,
        "force" : 70,
        "attack":15,
        "damage": 65,
        "lvl" : 10,
        "skill_name" : "有如鬼魅",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
        "dodge" :20,
        "force" : 80,
        "attack":15,
        "damage": 70,
        "lvl" : 20,
        "skill_name" : "疾冲上前",
        "damage_type":  "刺伤"
]),
([      "action":"$N喝道：“好！”，便即拔出$w，反手刺出，跟着转身离去",
        "dodge" :20,
        "force" : 80,
        "attack":15,
        "damage": 100,
        "lvl" : 30,
        "skill_name" : "反手刺出",
        "damage_type":  "刺伤"
]),
([      "action":"$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开",
        "dodge" :20,
        "force" : 90,
        "damage": 100,
        "attack":15,
        "unparryable":10,
        "lvl" : 50,
        "skill_name" : "眼前一花",
        "damage_type":  "刺伤"
]),
([      "action":"$N向后疾退，$n紧追两步，突然间$N闪到$n面前，手中$w直指$n的$l",
        "parry" :15,
         "force" : 90,
        "damage": 120,
        "attack":20,
        "unparryable":10,
        "lvl" : 80,
        "skill_name" : "向后疾退",
        "damage_type":  "刺伤"
]),
([      "action":"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向",
        "dodge" :20,
        "parry" :35,
        "force" : 100,
        "attack":25,
        "damage": 130,
        "lvl" : 100,
        "unparryable":10,
        "skill_name" : "直刺右眼",
        "damage_type":  "刺伤"
]),
([      "action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
        "dodge" :20,
        "parry" :35,
         "force" : 120,
        "damage": 150,
        "attack":25,
        "unparryable":10,
        "lvl" : 150,
        "skill_name" : "飞身跃起",
        "damage_type":  "刺伤"
]),
([      "action":"$N腰枝猛摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
        "force" : 140,
        "dodge" : 30,
        "parry" :35,
        "attack":35,
        "damage": 180,
        "undodgeable":10,
        "unparryable":10,
        "lvl" : 200,
        "skill_name" : "腰枝猛摆",
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) 
{ 
   return usage == "sword" || usage == "parry";
  
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
        level   = (int) me->query_skill("pixie-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int valid_learn(object me)
{
/*      if( me->query_skill("pixie-sword",1) < 90 ) 
                return notify_fail("辟邪剑法的入门只能通过研习《葵花宝典》来学习。\n");
        else 
*/
if ( (string)me->query("gender")=="女性")
                return notify_fail("这不是女人能练的剑法.\n");
        else if ( (string)me->query("gender")=="男性")
                return notify_fail("练辟邪剑法必须先"+RED"自宫\n"NOR);
        else return 1;
}

int practice_skill(object me)
{
       object ob;
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if( (int) me->query_skill("pixie-sword", 1) < 220)
                return notify_fail("你的辟邪剑法等级太低，还无法自行练习。\n");
        if( (int)me->query("kee") < 200 )
                return notify_fail("你的气不够，没有办法练习辟邪剑法。\n");
        me->receive_damage("kee", 100);
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"pixie-sword/" + action;
}

int attack_ratio() {
        return 100;
}

int counter_attack_ratio() {

        return 100;
}

int effective_level() {
        return 15;
}

int query_faith_req(int skill) {
        return skill*10+13;
}
mapping enable_req() {

        return( ([ 
                "force":"kuihua-shengong",      
        ]) );

}


int query_sheng_ke(string skill) {
        if(skill == "dugu-jiujian") return -300;
        if(skill == "taiji-jian") return 300;

        return 0;
}

