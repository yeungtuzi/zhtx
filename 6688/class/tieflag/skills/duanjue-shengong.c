/* duanjue-shengong.c
   lazypig(10/5/2003)

    断绝神功

   乃彩虹七剑之紫心剑客盛存孝偷练的武功，可作为内功和剑法，将摄心术融入剑法。可通过练习来提高，不可与任何其他内功兼容。
   可通过解密习得，作剑时，中性id使出来威力更大。

*/
// 14
#include <ansi.h>

inherit FORCE;

mapping *action = ({ 
([     "action" :  GRN"$N一招"MAG"风华正茂"GRN"，$n竟似处在一个春天的花园里面，宁静中洋溢着祥和与美丽，\n"
                      "那里还感觉得到$N的浓浓的杀气"NOR,

       "force"   :    10,
       "damage"  :    20,
       "attack"  :    20,
       "undodgeable": 2,
       "unparryable": 2,
       "lvl"     :    0,
       "damage_type": "刺伤",
]),
([     "action" : CYN"$n看着$N手中的$w，想起了曾经相爱过的人，竟然忘了自己身在战斗中,\n"
                     "直到$N轻叹道"MAG"奈何多情"CYN"$n方才发觉神魂已为对方所惑"NOR,
       "force"   :    40,
       "damage"  :    40,
       "attack"  :    20,
       "undodgeable": 5,
       "lvl"     :    60,
       "damage_type": "刺伤",
]),
([     "action" : BLU"$N轻挥$w，一个可爱的小宝宝的影子浮现在$n的眼前。$n刚想伸手去拥它，\n"
                  "突然一道剑芒将影子削散，$n心中大恸。原来$N竟然将摄心术融入剑中，\n"
                  "让$n受到"MAG"无后之最"BLU"的重创"NOR,
       "force"   :    80,
       "damage"  :    80,
       "attack"  :    30,
       "unparryable": 10,
       "lvl"     :    120,
       "damage_type": "刺伤",
]),
([     "action" : YEL"$n只见$N将手中$w向空中一扔，双手捧住脸，泪如泉水般从指缝涌了出来，浑不怕旁人笑话,\n"
                  "$n正迷惑间，一柄闪着青光$w离$n的眉尖还不到半寸，方才警觉对方的剑着居然可以让\n"
                  "人产生幻觉，正是失传已久的"MAG"向隅而泣"NOR,
       "force"   :    150,
       "damage"  :    150,
       "attack"  :    50,
       "undodgeable": 30,
       "lvl"     :    200,
       "damage_type": "刺伤",
]),
([     "action" : WHT"$n透过$N的剑意，感到他那如"MAG"大江东去"WHT"悲壮与豪迈，想起了那为了母亲而不惜练习这门功夫，\n"
                 "最终创下此招的盛存孝，不由的陷入了沉思，战若何,和若何?连$N的剑尖刺中$n都不知道"NOR,
       "force"   :    200,
       "damage"  :    200,
       "attack"  :    50,
       "undodgeable": 20,
       "unparryable": 20,
       "lvl"     :    251,
       "damage_type": "刺伤",
]),
});

//58
string query_force_type() { 

   return "断绝神功";

}
string *parry_msg = ({
        "$n不躲不闪,双眼凝视着$N,$N一呆,居然忘了攻击。\n",
        "$n手中长剑似是乱舞,$N竟然发现眼前已无$n的踪迹。\n",
});
//10
string *unarmed_parry_msg = ({
        "$n不躲不闪,双眼凝视着$N,$N一呆,居然忘了攻击。\n",
        "$n施展出「大江东去」，轻描淡写的化解了$N的攻势。\n",
});
int valid_enable(string usage) { 

      object me;

      me = this_player();
      if(me->query_skill_mapped("force")=="duanjue-shengong")
         return (usage == "force" || usage == "sword" || usage == "parry"); 
      return(usage=="force");
}

int practice_skill(object me)
{
        object weapon;

        int iMax_force,iPing_jing , iCost_kee , iCost_force;

        iPing_jing = ( (int) me->query_skill("force",1) + me->query_skill("force")/5 )*10; //内力瓶颈
        iMax_force = me->query("max_force");
//        printf("iPing_jing is %d\n",iPing_jing);

        if ( iMax_force < iPing_jing ) return notify_fail("你的功力尚未达到最佳状态，无法练习断绝神功。\n");
        if ( iMax_force > iPing_jing ) return notify_fail("你的功力太高，强行练习断绝神功会走火入魔的。\n");

        iCost_kee = 30 + (int) me->query_skill("duanjue-shengong",1)/2;
        iCost_force = 10 + (int) me->query_skill("duanjue-shengong",1)/4;

        if ((int)me->query("force") < iCost_force+1)
                return notify_fail("内力不够怎么练习？\n");
         if ((int)me->query("kee") < iCost_kee+1)
                return notify_fail("都没气了还练，不要命了?\n");

        me->receive_damage("kee", iCost_kee);
        me->add("force", -1*iCost_force);
        return 1;
}
string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}
mapping query_action(object me, object weapon)
{
       int i,level;
       level = (int) me->query_skill("duanjue-shengong",1);
         for(i=sizeof(action);i>0;i--)
           if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];       
}

int effective_level()
{
  object me;

  me = this_player();
  if( (string)me->query("gender") == "中性")
      return 20;
  return 5;
}

string exert_function_file(string func)
{
    return __DIR__"duanjue-shengong/" + func;
}

string perform_action_file(string action)
{
        return __DIR__"duanjue-shengong/"  + action;
}

int counter_attack_ratio()
{
  object me;

  me = this_player();

  if( (string)me->query("gender") == "中性")
      return 100;
  return 10;
}

int help(object me)
{
        write(@HELP

        断绝神功是一门和任何内功都不相调和的中性内功，还可以作为
剑法和招架功夫。
        作为内功时可以: exert heal,
                        exert powerup
        作为剑法时可以: perform sword.shexin

HELP
        );
        return 1;
}



