// chan.c 太极剑法「缠」字诀
// copy from sj

#include <ansi.h>
inherit F_SSERVER;
int checking(object me, object target, object weapon);
void remove_effect(object me);

string *number_msg = ({"一","二","三","四","五","六","七","八","九","十","十数","千百","无数"});
string *sword_msg = ({"反撩","斜刺","上挑","下划","正劈","直刺","后拉","前推"});

string *chan_msg = ({
CYN"$N以意驭剑，$S画出$R个"RED"圆圈"CYN"，其千变万化，无穷无尽，要去包裹缠住$n！\n" NOR,
CYN"$N以意驭剑，连绵不断地$S画出$R个"RED"圆圈"CYN"，前后排列，要将$n包裹起来！\n" NOR,
CYN"$N心中不存半点渣滓，以意驭剑，$W"CYN"每发一招，便似放出一条"RED"细丝"CYN"，要去缠住$n！\n"NOR,
CYN"$N神形归一，以意驭剑，$S画出$R个"RED"圆圈"CYN"，正反相交，要将$n缠在正中！\n" NOR,
CYN"$N手中$W"CYN"挥动，驱太极剑意散发出根根"RED"细丝"CYN"，要将$n裹起来！\n"NOR,
CYN"$N以意驭剑，$S一式，画出$R个"RED"圆圈"CYN"，上下包容，要将$n包裹起来！\n" NOR,
CYN"$N的一柄$W"CYN"画着一个个"RED"圆圈"CYN"，每一招均是以弧形刺出，以弧形收回，缠住$n！\n"NOR,
CYN"$N以意驭剑，连续$S画出$R个"RED"圆圈"CYN"，左右兼顾，要将$n缠在正中！\n" NOR,
});

string *dodged = ({
HIY"可是$n已然看穿了$P的招数，孤注一掷直入圈心，破了$N的太极剑意！\n\n" NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力中宫疾进，从剑光圈中冲了出去！\n\n"NOR,
HIY"$n微觉$N招数涩滞，急忙变招，竭尽全身之力飞跃后退，远离了剑圈！\n\n"NOR,
HIY"$n看得真切，回招挡格了$N中宫一剑，接着纵身一跃，已逃出圈外。\n\n"NOR,
});

string *chaned = ({
HIW"结果$n的招数渐见涩滞，偶尔发出一招，真气运得不足，便被$W"HIW"带着连转几个圈子。\n"NOR,
HIW"结果太极剑意散发出的细丝越积越多，似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"结果，剑气似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR,
HIW"$n越斗越是害怕，一个疏忽，被太极剑意紧紧裹了起来！\n"NOR,
});

int check_fight(object me, object target, object weapon);

int perform(object me, object target)
{
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
                
        if( me->query("family/family_name") != "武当派")
                return notify_fail("你不是武当正宗弟子，不会使用武当绝技！\n");

        if( me->query("faith") < 1500 )
                return notify_fail("你的门忠不够，不能使用「缠」字诀。\n");
                

        if(!living(target))
                return notify_fail("「缠」不能动的人？\n");
        if(!weapon || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得「缠」字诀？\n");
        if( me->query_temp("pfm/wudang_chan_last"))
                return notify_fail("你刚刚催动过「缠」字诀，真气周转不上，歇歇在用吧。\n");
        if( me->query_temp("pfm/wudang_chan"))
                return notify_fail("你正在使用「缠」字诀。\n");
        if( (int)me->query_temp("skill_mark/wudang_ninth") )
                return notify_fail("你正在使用「九宫连环」，与「缠」字诀剑意相反不能同时催动！。\n");  
                        
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        if( (int)me->query_skill("taiji-jian", 1) < 100 )
                return notify_fail("你的太极剑法极不够娴熟，不会使用「缠」字诀。\n");
        if( me->query("force") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("max_force") <= 1000 )
                return notify_fail("你的内力修为不够！\n");
        if( me->query_temp("combat_yield"))
                return notify_fail("你不出剑，何以使得「缠」字诀？\n");
        if( me->query_skill_mapped("sword") != "taiji-jian")
                 return notify_fail("你现在无法使用「缠」字诀。\n");
          if( me->is_busy() )
                    return notify_fail("你正忙着呢。\n");
        if(userp(me)){
            if (me->query_skill_mapped("parry") != "taiji-jian")
                return notify_fail("你现在无法使用「缠」字诀。\n");       
            if( (int)me->query_skill("taiji-shengong", 1) < 100 )
                return notify_fail("你的内功修为不够，不会使用「缠」字诀。\n");
            if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功与太极剑意气路相悖！\n");
        }        

        message_vision(CYN"\n$N使出太极剑法"RED"「缠」"CYN"字诀，一柄"+weapon->name()+CYN"在画着一个个圆圈，每一招均是以弧形刺出，弧形收回。
神在剑先，绵绵不绝，便如撒出了一张大网，逐步向$n收紧！\n\n"NOR, me, target);
        me->set_temp("pfm/wudang_chan", 1);
        checking(me, target, weapon);
        return 1;
}

int check_fight(object me, object target, object weapon)
{
        string msg;
        object wep;

        if (!me || !me->query_temp("pfm/wudang_chan") || !living(me) ) return 1;
        
        me->start_perform(1, "缠");
        me->delete_temp("pfm/wudang_chan");
        
        if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){ 
                if(!wep) msg = HIY"$N手中武器既失，圆转的太极剑幕也随之消散。\n"NOR;
                else if(!target) 
                         msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
                else  msg = HIY"$N亮出"+wep->name()+HIY"而撤回太极剑意，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
                me->start_busy(1);
                } 
        else if(!target) 
                msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
        
        else if(environment(me) != environment(target))
                msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;

        else if(!living(target) || (!me->is_fighting(target) && !me->is_killing(target->query("id")))){
                if(target && !living(target)) msg = HIY"$N不屑地望了$n一眼，将手中"+wep->name()+HIY"一向后摆，撤回了散开的剑幕．\n"NOR;
                else msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
                }           

        else if(wep != weapon && target->is_busy() 
                && random(me->query_skill("taiji-jian", 1)) < (int)target->query_skill("dodge", 1)/2){
                msg = HIY"$N撤后换剑，剑势顿时无法圆转如意，$n身边的太极剑幕威力骤减，使$n有了喘息之机会！\n"NOR;
                me->start_busy(1);
                }
       else if (userp(me) && (me->query_skill_mapped("sword") != "taiji-jian" || me->query_skill_mapped("parry") != "taiji-jian")){
                msg = HIY"$N突然变招，划破剑幕，使出和太极剑法完全不同的招数来！\n"NOR;
                if(target->is_busy()) target->start_busy(1);
                me->start_busy(1);
                }   
       else if( me->query("force") <= me->query_skill("taiji-jian", 1)/2 ){
                msg = HIY"$N剑招渐见涩滞，偶尔一剑刺出竟然软弱无力，原来是真气不足了！\n"NOR;
                me->start_busy(1);
                }           

       else if(!target->is_busy() && !me->is_busy() && random(3)==1 && living(target)){ 
                checking(me, target, wep);
                return 1;
                }
       else {
                me->set_temp("pfm/wudang_chan", 1);
                call_out("check_fight", 1, me, target, wep);
                return 1;
                }
       message_vision(msg, me, target);  
       return 1;
}       


int checking(object me, object target, object weapon)
{
       string msg;
       int ap, dp, cost, skill;
       
       skill = (int)me->query_skill("sword",1) + (int)me->query_skill("taiji-jian",1);
       cost = me->query_skill("taiji-jian", 1);
       ap = me->query("combat_exp")/1000 * me->query_skill("taiji-jian",1) * me->query_int();
       dp = target->query("combat_exp")/1000 * target->query_skill("dodge",1) * target->query_int();
       if (ap < 1) ap = 1;
       if (dp < 1) dp = 1;
       
       msg = chan_msg[random(sizeof(chan_msg))];
       msg = replace_string(msg, "$S", sword_msg[random(sizeof(sword_msg))]);
       msg = replace_string(msg, "$R", number_msg[random(sizeof(number_msg))]);
       msg = replace_string(msg, "$W", weapon->name());
                
       me->add("force", -cost*2);
       if(random(ap + dp) > dp){          
                target->start_busy(3+random(cost/20));
                msg += chaned[random(sizeof(chaned))];
                msg = replace_string(msg, "$W", weapon->name());
                me->set_temp("pfm/wudang_chan", 1);
                me->start_perform(1, "缠");
                me->set_temp("pfm/wudang_chan_last",1);
                call_out("check_fight", 1, me, target, weapon);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/10);
               }
       else{
                me->start_busy(3+random(2));
                msg += dodged[random(sizeof(dodged))];
                msg = replace_string(msg, "$W", weapon->name());
                me->delete_temp("pfm/wudang_chan");
                }
       message_vision(msg, me, target);
       return 1;
}       

void remove_effect(object me)
{
        me->delete_temp("pfm/wudang_chan_last");
        tell_object(me, "你感觉体内真气充实，看来又可以使用「缠」字诀了。\n");
}


int help(object me)
{
        write(WHT"\n太极剑「缠字诀」："NOR"\n");
        write(@HELP
        太极剑意圆转不断，连绵不绝，临敌人之际以意驭剑，使出「缠」字诀每发
        一招，便似放出一条细丝，缠住对手，千变万化，无穷无尽，使其无法动作，
        并且可以自动不断连续发出，直至击败对手。
        
        要求：  最大内力 1000 以上；      
                内力 500 以上； 
                太极剑等级 100 以上；
                氤氲紫气等级 100 以上；
                技法太极剑为招架；
                并未设制打不还手。     
HELP
        );
        return 1;
}

