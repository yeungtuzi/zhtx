/* cuixin-zhang.c*/
 
inherit SKILL;
#include <ansi.h>
mapping *action = ({
         ([      "action":               
 "$N左手向后一引，右手一招「云罩九霄」拍向$n$l",
                 "dodge":                25,
                 "parry":                15,
                 "attack":               20,  
                 "force":                200,
                 "damage_type":  "掌伤",
                 "weapon":               "右手手掌",
         ]),
         ([      "action":               
 "$N近身欺上,双掌平推,一招「摧枯拉朽」往$n的$l攻去",
                 "dodge":                15,
                 "parry":                20,
                 "attack":               25,
                 "force":                400,
                 "lvl":                  150,
                 "damage_type":  "口伤",
                 "weapon":               "双手手掌",
         ]),
         ([      "action":               
 "$N身影飘忽不定，左手一扬使出「无坚不摧」往$n的$l拍去", 
                 "dodge":                25,
                 "parry":                15,
                 "attack":               30,
                 "force":                500,
                 "unparryable":          20,
                 "lvl":                  200,
                 "damage_type":  "掌伤",
                 "weapon":               "左手手掌",
         ]),
         ([      "action":               
 "只见$N运劲于掌，右手手掌一翻,一招「辣手摧心」往$n的$l抢攻过去",
                 "dodge":                30,
                 "parry":                30,
                 "attack":               40,
                 "force":                600,
                 "unparryable":          30,
                 "lvl":                  250,
                 "damage_type":  "掌伤",
                 "weapon":               "右手手掌",
         ]),
});
 
int valid_learn(object me)
{       if( (int)me->query("max_force") < 100 )
                 return notify_fail("你的内力不够，没有办法练习摧心掌。\n");
         if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                 return notify_fail("练习摧心掌必须空手。\n");
         return 1;
} 
 
int valid_enable(string usage)
{
         return usage=="strike" || usage=="parry";
}

int valid_combine(string combo) { return combo=="cuixin-zhang"; }
 
mapping query_action(object me, object weapon)
{
         return action[random(sizeof(action))];
}
 
 
int practice_skill(object me)
{     
         if( (int)me->query("kee") < 35 )
                 return notify_fail("你的身体状况太差了，休息一下再练吧。\n");
         if( (int)me->query("force") < 5 )
                 return notify_fail("你的内力不够了。\n");
 
         me->receive_damage("kee", 35);
         me->add("force", -5);
         return 1;
} 

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int menforce,tenforce,fenforce;
        tenforce = victim->query("force_factor"); 
        menforce = me->query("force_factor"); 
        fenforce = (tenforce - menforce/3)*9/10;
        if ( fenforce < 0 ) fenforce = 0;
        if( random(3) > 1) return 0;
          if ( fenforce < 10 ) 
          {
          victim->add("force", -victim->query("force")/2);
          victim->set("force_factor", fenforce);
          return RED "只听得「乒乒乓乓」数声，$n顿觉气血凝结，原来心脉竟已被$N用摧心掌力齐齐震碎！\n" NOR;
          }
          else if ( fenforce > 9 && fenforce < 100 ) 
          {
          victim->add("force", -victim->query("force")/8);
          victim->set("force_factor", fenforce);
          return YEL "「砰」的一声闷响，$n已觉得真气运行颇为不畅，竟在$N摧心掌力下吃了暗亏！\n" NOR;
          }
          else
          {
          victim->add("force", -victim->query("force")/16);
          victim->set("force_factor", fenforce);
          return HIG "$n轻哼了一声，头顶冒出丝丝白气，耗费了不少真元才将$N的摧心掌力一一化解！\n" NOR;
          }

} 

int query_faith_req(int skill) {
        return 10*skill+1;
}

