/* xiaoxiang-jianjue.c
  Made by lazypig(10/5/2003) 
  削香剑诀

  朱家家传剑法

  暗香浮动月黄昏 231
  
  灰飞烟灭樯橹间 182
  为伊消得人憔悴 100 
  消魂独我情何限 50
  人生愁恨何能免 0  
    
  */

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([           "action" : CYN"$N随手乱舞,一边唱道:"HIR"人生愁恨何能免"CYN",长剑似是无意的指向$n的$l"NOR,

             "dodge"  : 10,
             "parry"  : 5,           
             "force"  : 20,
             "damage" : 50,
             "lvl"    : 0,
             "damage_type": "刺伤"
]),
([           "action" : GRN"$N一招"HIR"消魂独我情何限"GRN",手中长剑奔雷般涌向$n"NOR,

             "attack" : 20, 
             "parry"  :-5,           
             "force"  : 80,
             "damage" : 80,
             "lvl"    : 49,
             "damage_type": "刺伤"
]),
([           "action" : WHT"只见$N手中$w越舞越快，剑气反而越来越弱，但是$n的身法 \n"
                           "却越发迟钝，当$N手中$w沿着$n手臂划至指尖，$n才发现自 \n"
                           "己已经中了对方的剑招"HIR"为伊消得人憔悴"NOR,
             "attack" : 30, 
             "parry"  :-10,           
             "force"  : 150,
             "damage" : 100,
             "lvl"    : 99,
             "undodgeable": 10,
             "damage_type": "刺伤"
]),
([           "action" : YEL"$n只见四面皆是各式影子,$N一招"HIR"灰飞烟灭樯橹间"YEL",\n"
                           "让$n避无可避,徒见对方$w从八方刺了过来"NOR,

             "attack" : 35, 
             "parry"  :-10,           
             "force"  : 200,
             "damage" : 200,
             "lvl"    : 181,
             "unparryable": 30,
             "damage_type": "刺伤"
]),
([           "action" : MAG"天空突然一片混暗，朦胧中只见两道剑影，当$n试图隔挡时，方才发觉对方长剑\n"
                           "已从背后袭来，正是传说中的"HIR"暗香浮动月黄昏"NOR,
             "attack" : 50, 
             "dodge"  :-30,           
             "force"  : 300,
             "damage" : 250,
             "lvl"    : 230,
             "unparryable": 30,
             "undodgeable": 20,
             "damage_type": "刺伤"
]),
});
 
  int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

  int valid_learn(object me)
  {
    if ((int)me->query("max_force") < 500)
            return notify_fail("你的内力不够,不能学习削香剑诀\n");
    if ((int)me->query_skill("sword", 1) < 100)
            return notify_fail("你的基本剑术不够,不能学习削香剑诀\n");
    return 1;
  }

 mapping query_action(object me, object weapon)
 {
        int i,level;
       level = (int) me->query_skill("xiaoxiang",1);
         for(i=sizeof(action);i>0;i--)
           if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];       
}

int practice_skill(object me)
{
object ob;
if( !(ob = me->query_temp("weapon"))
||    (string)ob->query("skill_type") != "sword" )
       return notify_fail("没搞错吧,你!不拿剑都想练剑,你以为你是段誉阿\n");
     if( (int)me->query("kee") < 10 )
       return notify_fail("这么点气都要练,你不要命了?\n");
       me->receive_damage("kee", 10);
  return 1;
}

string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
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

string perform_action_file(string action)
{
        return __DIR__"xiaoxiang/" + action;
}

/*
mapping enable_req() {

        return( ([ 
                "force":"yunhai-force",        
        ]) );

}
*/

int query_faith_req(int skill) {
        return 10+skill*15;
}

mapping level_req(int level) {
  
    return ( ([
               "sword":100,
        ]) );
}


