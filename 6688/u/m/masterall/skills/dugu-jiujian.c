// dugu-jiujian.c 独孤九剑
#include <combat.h>
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      
        "action" : "$N斜斜得向$n的$1刺出一剑，所刺之出令人出乎意料。",
        "force" : 10,
        "parry" : 10,
        "attack": 10,
        "damage" : 100,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N向前跨上一步，右手$w平淡无奇的伸向$n的$l，根本无招可言。",
        "force" : 20,
        "parry" : 10,
        "attack": 10,
        "damage" : 100,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N手中$w突然撞向自己的$l，就在此时，一转向$n的$l挥去。",
        "force" : 40,
        "parry" : 15,
                  "attack": 15,
        "damage" : 100,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N将手中$w舞成一片，直砍$n的$l",
        "force" : 50,
        "parry" : 20,
             "attack": 15,
        "damage" : 100,
        "lvl" : 30,
        "unparryable" : 10,
        "damage_type" : "砍伤"
]),
([      
        "action" : "$N突然将$w抛向空中，剑锋直向$n的$l刺去。$N跟上一步，又接住了$w。",
        "force" : 60,
        "parry" : 20,
             "attack": 20,
        "damage" : 120,
        "unparryable" : 10,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N身形急转，$w从一个不可思意的角度刺向$n的$l",
        "force" : 60,
        "parry" : 30,
             "attack": 20,
        "damage" : 140,
        "lvl" : 70,
        "unparryable" : 10,
        "damage_type" : "刺伤"
]),
([      
        "action" : "$N身子一晃，抢步上前，出人意料的将$w交给左手，右食指点向$n的$l",
        "force" : 70,
        "parry" : 30,
             "attack": 25,
        "damage" : 160,
        "lvl" : 100,
        "unparryable" : 10,
        "damage_type" : "瘀伤"
]),
([      
        "action" : "$N右腿半屈般蹲，剑尖虚指，转身撩向$n的$l",
        "force" : 80,
        "parry" : 30,
             "attack": 25,
        "damage" :180 ,
        "lvl" : 120,
        "unparryable" : 10,
        "damage_type" : "刺伤"
]),
([ 
        "action" : "$N回身拧腰，右手虚抱，$w中宫直进，刺向$n的$l",
        "force" : 100,
        "dodge" : 30,
             "attack": 30,
        "damage" : 200,
        "lvl" : 160,
        "unparryable" : 10,
        "damage_type" : "刺伤"
]),
});


mapping op_action =
([      
        "action" : "$w"+HIC"轻飘飘的在半空中突然打了个盘旋，剑尖一弯，迅捷轻盈地又向$n攻了过来！\n"NOR,
        "force" : 50,
        "parry" : 30,
        "attack": 20,
        "undodgeable": 20,
        "damage" : 120,
        "damage_type" : "刺伤"
]);


string *parry_msg = ({
        "待$N的$w攻至，$n侧身向右，$v便向$N左肩削去。\n",
        "$n眼见难以闪避，一抖手，$v指向$N胸膛。\n",
        "$n$v回击，反剑刺出，指向$N的肚脐。\n",
        "$n眼见$N的$w猛劈而至，长剑斜挑，径刺$N小腹，自己上身一侧，已然避开了$N的$w。\n",
        "$n一眼便看到$N招式中的破绽所在，随手出剑，迫得$N回剑自保。\n",
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
        if(me->query_skill("huashan-jianfa",1)<150 && me->query_skill("sword",1)<150)
                          return notify_fail("你的剑术修为太低，无法领会独孤九剑的奥秘");
                  if(me->query_skill("zong-jue",1)+19<me->query_skill("dugu-jiujian",1)
                   &&me->query_skill("dugu-jiujian",1)<280)
                return notify_fail("你的「总诀式」修为太低，无法进一步领会独孤九剑的奥秘。\n");
/*        if(me->query("family/master_id")!="feng qingyang")
                return notify_fail("独孤九剑只能向风清扬学。\n");
*/
        return 1;
}



mapping query_action(object me, object weapon)
{
        int i, level;
        object victim;
        level = (int) me->query_skill("dugu-jiujian", 1);


        if(  (weapon = me->query_temp("weapon")) && weapon->query("id") == "ziwei ruanjian" ) && random(skill)> 200)
        {
        //用紫薇软剑的效果
        //                me->set_temp("skill_mark/wind-sword-counting",1);
                        me->clean_up_enemy();
                        victim = me->select_opponent();
                        if( objectp(victim) )  
                        {
                                message_vision(op_action["action"],me,victim);
                                COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_SELFATTACK,op_action);
                        }
        }

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
        if( (int) me->query_skill("dugu-jiujian", 1) < 250)
                return notify_fail("你的独孤九剑等级太低，还无法自行练习。\n");
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的内力或气不够，没有办法练习独孤九剑。\n");
        me->receive_damage("kee", 40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}

int counter_attack_ratio() {

        return 100;
}

int attack_ratio() {
        return 100;
}

int query_sheng_ke(string skill) 
{
      if(skill == "pixie-sword" ) return 300;
   if(skill == "taiji-jian") return 100;
        return 300;
}

/*mapping enable_req() 
{
        if( this_player()->query_skill_mapped("dodge")=="yan-shuangfei" )
        return( ([ 
                "dodge":"yan-shuangfei",        
        ]) );
        else
        return( ([ 
                "dodge":"yanshuangfei", 
        ]) );

}*/

mapping enable_req() {

        if( this_player()->query_skill_mapped("force") == "huashan-neigong" )
        return( ([ 
                "force":"huashan-neigong",     
        ]) );
        else
        return( ([ 
                "force":"zixia-shengong",   
        ]) );

}

mapping level_req(int level) 
{

        return( ([
                "sword":220,    
                "huashan-jianfa":220,
        ]) );
}

int effective_level() {
        return 20;
}

int query_faith_req(int skill) 
{
        return 10*skill+1;
}

