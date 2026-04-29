//eight_drunk 八仙醉打
//天魔十式
//by masterall
#include <ansi.h>
#include <weapon.h>
inherit F_DBASE;
inherit SSERVER;           
#include <combat.h>


varargs show_combat_msg(int level,object me,object victim,object weapon,mapping action,string attack_skill)
{
        string limb, *limbs, result;
        
        result = "\n" + action["action"];
        limbs = victim->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        
        if( limb )
                result = replace_string( result, "$l", limb );

        if( victim->query_skill_mapped("iron-cloth"))
                  result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));
 
        if( victim->query_temp("weapon"))
        result = replace_string( result, "$v", victim->query_temp("weapon")->name() );

        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
        else if( action && stringp(action["weapon"]) )
                result = replace_string( result, "$w", action["weapon"] );
        else if( attack_skill == "finger" )
                result = replace_string( result, "$w", "手指" );
        else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "手掌" );
        else result = replace_string( result, "$w", "拳头" );
        
        result += "！\n";

        message_combat(level,result, me, victim );
}

void post_action1(object me, object victim, int damage_bonus)
{}

void post_action2(object me, object victim, int damage_bonus)
{} 

void post_action3(object me, object victim, int damage_bonus)
{}

void post_action4(object me, object victim, int damage_bonus)
{}

void post_action5(object me, object victim, int damage_bonus)
{}

void post_action6(object me, object victim, int damage_bonus)
{}

void post_action7(object me, object victim, int damage_bonus)
{}

void post_action8(object me, object victim, int damage_bonus)
{}

mapping *actions = ({
([      "action" : "「"+HIB"蓝采和，提篮劝酒醉朦胧"+NOR"」，$N手中$w半提，缓缓划向$n的$l",
        "force" : 200,
        "dodge" : -15,
        "parry" : -15, 
        "attack" : 25,
        "damage" : 100,
        "undodgeable" : 10,
        "post_action":  (: call_other, __FILE__, "post_action1" :),
        "skill_name" : "蓝采和，提篮劝酒醉朦胧",
        "damage_type" : "挫伤"
]),
([      "action" : "「"+HIM"何仙姑，拦腰敬酒醉仙步"+NOR"」，$N左掌护胸，右臂挟棍猛地扫向$n的腰间",
        "force" : 180,
        "dodge" : -10,
        "attack" : 25,
        "damage" : 100,
        "undodgeable" : 10,
        "skill_name" : "何仙姑，拦腰敬酒醉仙步", 
        "post_action" : (: call_other, __FILE__, "post_action2" :),
        "damage_type" : "挫伤"
]),
([      "action":"「"+HIY"曹国舅，千杯不醉倒金盅"+NOR"」，$N倒竖$w，指天打地，向$n的$l劈去",
        "force" : 180,
        "dodge" : -5,
        "attack" : 25,
        "damage": 100,
        "undodgeable" : 10,
        "skill_name" : "曹国舅，千杯不醉倒金盅",
        "post_action" : (: call_other, __FILE__, "post_action3" :),
        "damage_type":  "挫伤"
]),
([      "action" : "「"+HIG"韩湘子，铁棍提胸醉拔萧"+NOR"」，$N横提$w，棍端划了个半圈，击向$n的$l",
        "force" : 190,
        "dodge" : -10,
        "attack" : 25,
        "damage" : 100,
        "undodgeable" : 10,
        "skill_name" : "韩湘子，铁棍提胸醉拔萧",
        "post_action" : (: call_other, __FILE__, "post_action4" :),
        "damage_type" : "挫伤"
]),
([      "action" : "「"+HIC"汉钟离，跌步翻身醉盘龙"+NOR"」，$N手中棍花团团，疾风般向卷向$n",
        "force" : 200,
        "dodge" : -20,
        "attack" : 25,
        "damage" : 100,
        "undodgeable" : 10,
        "skill_name" : "汉钟离，跌步翻身醉盘龙",
        "post_action" : (: call_other, __FILE__, "post_action5" :),
        "damage_type" : "挫伤"
]),
([      "action": "「"+HIR"铁拐李，踢倒金山醉玉池"+NOR"」，$N单腿支地，一腿一棍齐齐击向$n的$l",
        "dodge": -5,
        "parry": -10,
        "force": 480,
        "damage": 120,
        "attack": 30,
        "undodgeable" : 10,
        "skill_name" : "铁拐李，踢倒金山醉玉池",
        "post_action" : (: call_other, __FILE__, "post_action6" :),
        "damage_type": "挫伤"
]),
([      "action" : "「"+YEL"张果老，醉酒抛杯倒骑驴"+NOR"」，$N扭身反背，$w从胯底钻出，戳向$n的胸口",
        "force" : 180,
         "attack" : 40,
        "dodge" : -20,
        "parry" : -10,
        "damage" : 140,
        "undodgeable" : 10,
        "skill_name" : "张果老，醉酒抛杯倒骑驴",
        "post_action" : (: call_other, __FILE__, "post_action7" :),
        "damage_type" : "挫伤"
]),
([      "action" : "「"+HIW"吕洞宾，酒醉提壶力千钧"+NOR"」，$N腾空而起，如山棍影，疾疾压向$n",
        "force" : 160,
        "dodge" : -20,
        "attack" : 40,
        "damage" : 160,
        "undodgeable" : 10,
        "skill_name" : "吕洞宾，酒醉提壶力千钧",
        "post_action" : (: call_other, __FILE__, "post_action8" :),
        "damage_type" : "挫伤"
]),
});

int perform(object me, object target)
{
        int drunk,skill,num,i;
        object weapon;
        drunk = me->query_condition("drunk");
        if(drunk > 50 ) drunk = 50;
        weapon = me->query_temp("weapon");
        skill = me->query_skill("zui-gun", 1);

        if( !me->is_fighting() )
                return notify_fail("「八仙醉打」只能在战斗中施用。\n");       
                       
        if( me->is_busy())
                return notify_fail("你正忙着呢，来不及用「八仙醉打」。\n");

        if( me->query_condition("drunk") < 20 )
                return notify_fail("你全无酒意，如何使用「八仙醉打」?\n"); 
        
        if( (int)me->query("force") < 2000 ) return notify_fail("你的内力不够。\n");

        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="staff" )
                return notify_fail("使用「少林醉棍」必须手中有棍。\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("你必须使用少林正宗神功——混元一气功！\n");
        
        if( me->query_skill_mapped("staff") != "zui-gun" )
                return notify_fail("只有少林醉棍才可以使用「八仙醉打」。\n");

        if( me->query_skill_mapped("parry") != "zui-gun" )
                return notify_fail("只有少林醉棍才可以使用「八仙醉打」。\n");
         
        if( !target || target == me ) target = offensive_target(me);

        if( me->query_skill("zui-gun", 1) < 200 ) 
                return notify_fail("你的「少林醉棍」招式不够娴熟，无法使用「八仙醉打」。\n"); 


        message_vision(HIY"$N笑吟道“"+HIR"醉卧沙场君莫笑，古来征战几人回。"+HIY"$n"+ RANK_D->query_respect(target)+"不如来陪贫僧痛饮至天明吧。”\n$n闻到$N酒气扑鼻，几欲作呕，却不想$N手中"+weapon->name()+HIY"猛的探出，一番排山倒海般的攻势向$n奔涌而来！！\n"NOR, me, target);

        num = drunk*3 + skill/2;
        me->add_temp("apply/attack",num);
        me->add_temp("apply/damage",num);
        me->add("force",-1000);
        for(i=0;i<8;i++)
        {

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIG"$N冷哼了一声，“敬酒不吃吃罚酒，这回知道本和尚的厉害了吧。”\n"+HIR"随即一个站立不稳，跌倒在地，竟然枕着"+weapon->name()+HIR"沉沉睡去。\n"NOR,me);
                        me->clear_condition("drunk");
                        if( random( me->query_con() ) < 1 ) me->unconcious();
                        break;
                }       

                show_combat_msg(5,me,target,weapon,actions[i],"staff");
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_SELFATTACK,actions[i]);
        }
        message_vision(HIW"\n$N酒性大发，连道“痛快！痛快！来来来，再让贫僧与尔大战三百合！！”\n"NOR,me);
        me->start_busy(3);
        me->add_temp("apply/attack",-num);
        me->add_temp("apply/damage",-num);
        return 1;
}
