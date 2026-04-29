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

void post_action9(object me, object victim, int damage_bonus)
{}

void post_action10(object me, object victim, int damage_bonus)
{}


mapping *actions = ({
([      "action" : "「"+BLK"绝式天魔击碎霸！"+NOR"」\n$N一招「雷霆震怒鬼神惊」,"+BLK"雷神魔锤"+NOR"挟万钧之势砸向$n",
        "force" : 200,
        "dodge" : -5,
        "parry" : -5, 
        "attack" : 20,
        "damage" : 100,
        "unparryable" : 10,
        "post_action":  (: call_other, __FILE__, "post_action1" :),
        "skill_name" : "雷霆震怒鬼神惊",
        "weapon":     "雷神魔锤",
        "damage_type" : "瘀伤"
]),
([      "action" : "「"+HIM"无相真魔极乐杀！"+NOR"」\n$N一招「一川碎石大如斗」,"+HIM"灭世魔刀"+NOR"泛起一片雷霆般的刀光，向$n的全身涌去",
        "force" : 180,
        "dodge" : 10,
        "attack" : 20,
        "damage" : 100,
        "unparryable" : 10,
        "skill_name" : "一川碎石大如斗",
        "weapon":     "灭世魔刀",
        "post_action" : (: call_other, __FILE__, "post_action2" :),
        "damage_type" : "割伤"
]),
([      "action":"「"+HIC"域外魔飘虚空狂！"+NOR"」\n$N一式「天长路远魂飞苦」，"+HIC"断玉魔钩"+NOR"猛地向$n的$l刺出!",
        "force" : 180,
        "dodge" : 5,
        "attack" : 20,
        "damage": 100,
        "unparryable" : 10,
        "skill_name" : "天长路远魂飞苦",
        "weapon":     "断玉魔钩",
        "post_action" : (: call_other, __FILE__, "post_action3" :),
        "damage_type":  "刺伤"
]),
([      "action" : "「"+HIR"天魔邪魂大破灭！"+NOR"」\n$N一招「一身转战三千里」,天地变色!"+HIR"破天魔斧"+NOR"斧风如火!劈向$n的全身!",
        "force" : 190,
        "dodge" : 10,
        "attack" : 20,
        "damage" : 100,
        "unparryable" : 10,
        "skill_name" : "一身转战三千里",
        "weapon":     "破天魔斧",
        "post_action" : (: call_other, __FILE__, "post_action4" :),
        "damage_type" : "割伤"
]),
([      "action" : "「"+HIG"邪焱魔雷狂炎舞！"+NOR"」\n$N一招「试拂铁衣如雪色」,"+HIG"温侯魔戟"+NOR"戟光如雪，向$n的全身涌去",
        "force" : 200,
        "dodge" : 20,
        "attack" : 20,
        "damage" : 100,
        "unparryable" : 10,
        "skill_name" : "试拂铁衣如雪色",
        "weapon":     "温侯魔戟",
        "post_action" : (: call_other, __FILE__, "post_action5" :),
        "damage_type" : "割伤"
]),
([      "action": "「"+HIY"天魔雷击封八方！"+NOR"」\n$N大吼一声，双掌使出「黄河之水天上来」，"+HIY"震天魔手"+NOR"不顾一切般击向$n",
        "dodge": -5,
        "parry": -10,
        "force": 480,
        "damage": 120,
        "attack": 20,
       "unparryable" : 10,
        "unparryable" : 10,
        "skill_name" : "黄河之水天上来",
        "post_action" : (: call_other, __FILE__, "post_action6" :),
        "damage_type": "瘀伤"
]),
([      "action" : "「"+HIB"焚城魔神蚀天元！"+NOR"」\n$N一招「此恨绵绵无绝期」,"+HIB"毒龙魔鞭"+NOR"如虹，向$n的全身涌去",
        "force" : 180,
        "attack" : 10,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 100,
        "unparryable" : 10,
        "skill_name" : "此恨绵绵无绝期",
        "weapon":     "毒龙魔鞭",
        "post_action" : (: call_other, __FILE__, "post_action7" :),
        "damage_type" : "鞭伤"
]),
([      "action" : "「"+HIC"魔气莲华无神破！"+NOR"」\n$N一招「东风吹血腥」，用"+HIC"失魂魔叉"+NOR"的中部砸向$n的$l",
        "force" : 160,
        "dodge" : 20,
        "attack" : 20,
        "damage" : 100,
        "unparryable" : 10,
        "skill_name" : "东风吹血腥",
        "weapon":     "失魂魔叉",
        "post_action" : (: call_other, __FILE__, "post_action8" :),
        "damage_type" : "瘀伤"
]),
([      "action" : "「"+HIR"极乐魔煞孤魂灵！"+NOR"」\n$N一招「蜀道之难难於上青天」,"+HIR"刺日魔枪"+NOR"如游龙,人如飞凤向$n的$l刺去",
        "force" : 180,
        "dodge" : 20,
        "attack" : 20,
        "damage" : 200,
        "undodgeable" : 20,
        "skill_name" : "蜀道之难难於上青天",
        "weapon":     "刺日魔枪",
        "post_action" : (: call_other, __FILE__, "post_action9" :),
        "damage_type" : "刺伤"
]),
([      "action":"「"+HIW"十域天魔灭无神！"+NOR"」\n$N一式「天寒翠袖薄」，"+HIW"混世"+HIR"魔"+HIC"剑"+NOR"由下至上，如疾电般射向$n的胸口",
        "force" : 280,
        "dodge" : 5,
        "attack" : 25,
        "damage": 220,
        "unparryable" : 20,
        "undodgeable" : 20,
        "skill_name" : "天寒翠袖薄",
        "post_action" : (: call_other, __FILE__, "post_action10" :),
        "damage_type":  "刺伤"
]),
});

int perform(object me, object target)
{
    int skill1,skill2,skill3,skill4,skill5,skill6,skill7,skill8;
    int skill9,skill10,i,per_power,per_lev,victim_exp,num;
        object ob,weapon;
        if( !me->is_fighting() )
                return notify_fail("「霸杀狂灭舞，方元破灵神」只能在战斗中施用。\n");                              
        if( me->is_busy())
                return notify_fail("你正忙着呢，来不及用「霸杀狂灭舞，方元破灵神」。\n");

        if (!objectp(ob = present("hunshi mojian",me) ) )
                return notify_fail("你还没有得到混世魔剑，如何使用「霸杀狂灭舞，方元破灵神」。\n"); 
        
        if( (int)me->query("force") < 2000 ) return notify_fail("你的内力不够。\n");
        if( !objectp( weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="sword" )
                return notify_fail("「霸杀狂灭舞，方元破灵神」必须手中有剑。\n");

//   if( me->query_skill_mapped("force") != "tianmo-dafa")
//                return notify_fail("你必须使用独门神功——天魔大法！\n");
         
        if( !target || target == me ) target = offensive_target(me);

        skill1 = me->query_skill("mo-jian-jue",1);
        skill2 = me->query_skill("mo-qiang-jue",1);
        skill3 = me->query_skill("mo-fu-jue",1);
        skill4 = me->query_skill("mo-chui-jue",1);
        skill5 = me->query_skill("mo-bian-jue",1);
        skill6 = me->query_skill("mo-dao-jue",1);
        skill7 = me->query_skill("mo-gou-jue",1);
        skill8 = me->query_skill("mo-zhang-jue",1);
        skill9 = me->query_skill("mo-ji-jue",1);
        skill10 = me->query_skill("mo-cha-jue",1);
        num=skill1+skill2+skill3+skill4+skill5+skill6+skill7+skill8+skill9+skill10;

        if(userp(me))
                  {
          
                if( skill1 < 200 ) 
          return notify_fail("你的「魔剑诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill2 < 180 ) 
          return notify_fail("你的「魔枪诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill3 < 180 ) 
          return notify_fail("你的「魔斧诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill4 < 180 ) 
          return notify_fail("你的「魔锤诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill5 < 180 ) 
          return notify_fail("你的「魔鞭诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill6 < 180 ) 
          return notify_fail("你的「魔刀诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill7 < 180 ) 
          return notify_fail("你的「魔钩诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill8 < 180 ) 
          return notify_fail("你的「魔掌诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill9 < 180 ) 
          return notify_fail("你的「魔戟诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n"); 

                if( skill10 < 180 ) 
          return notify_fail("你的「魔叉诀」招式不够娴熟，使不出「霸杀狂灭舞，方元破灵神」。\n");              
        }    

        message_vision(HIR"$N将"+HIW"混世"+HIR"魔"+HIC"剑"+HIR"抛上虚空，朗声吟颂："+HIC"“霸杀狂灭舞，方元破灵神！”"+HIR"\n突然间一阵龙吟虎啸.................\n\n"+BLK"  雷神魔锤    "+HIM"灭世魔刀    "+HIC"断玉魔钩    \n"+HIR"  破天魔斧    "+HIG"温侯魔戟    "+HIY"震天魔手  \n"+HIB"  毒龙魔鞭  "+HIC"  失魂魔叉    "+HIR"刺日魔枪      "+NOR"\n"+NOR""+HIW"              混世"+HIR"魔"+HIC"剑\n\n"+HIR"分别从东、西、南、北、东南、东北、西南、西北、上、下，十个方位急袭而至！！！！！\n"NOR,me);
        me->add_temp("apply/attack",num/20);
        me->add("force",-1000);
        for(i=0;i<10;i++)
        {

                if(!objectp(target) 
                   || target->is_ghost() 
                   || target->query("eff_kee") < 1
                   || (environment(me)!=environment(target))
                   || me->is_ghost())             
                {
                        message_vision(HIG"$N"+HIW"混世"+HIR"魔"+HIC"剑"+HIG"一收，仰望上苍，停手不攻。\n"NOR,me);
                        break;
                }       
                
                if( !me->visible(target) )
                {
                        per_lev = (int)me->query_skill("perception",1);
                        per_power = per_lev*per_lev*per_lev;
                        victim_exp = (int)target->query("combat_exp");
                        per_power = random(per_power);
                        if(per_power<victim_exp/4)
                        {
                                if( per_power>victim_exp/8 )
                                message_vision(GRN"\n$N身形凝立不动，侧耳倾听。\n"NOR,me);
                                me->set_temp("guarding", 1);                            
                                continue;
                        }                               
                        message_vision(YEL"\n$N从$n衣袂带风声中感应出$n身形所在，趁势发动攻击！\n"NOR,me,target);
                }                       

                show_combat_msg(5,me,target,ob,actions[i],"sword");
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_SELFATTACK,actions[i]);
        }
        message_vision(HIG"\n$N剑势一收，十件神兵顿时化作一道道苍芒消失在天际，"+HIW"混世"+HIR"魔"+HIC"剑"+HIG"回到了$N的手中。\n"NOR,me);
        me->start_busy(3);
        me->add_temp("apply/attack",-num/20);
        return 1;
}

