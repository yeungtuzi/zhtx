#include <ansi.h>
#include <combat.h>
//inherit SSERVER;
inherit SKILL;

mapping *action2 = ({
([      "action" : "$N回身拧腰，右手虚抱，$w中宫直进，刺向$n的$l\n",
        "force" : 100,
        "dodge" : 30,
        "attack": 30,
        "damage" : 180,
        "unparryable" : 10,
        "damage_type" : "刺伤",
]),
});

int perform(object me,object victim,object weapon,int damage)
{
        int skill_level,i; 
        object *enemy;                                 
        object target,ob;
        
        me = this_player();

        if( !me->is_fighting() )
                return notify_fail("「破箭式」只能在战斗中使用。\n");

        if (!objectp(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用独孤九剑的「破箭式」。\n");     

        if( (int)me->query("kee") < 500 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("force") <  500 )
                return notify_fail("你的真气不够！\n");

        skill_level = me->query_skill("dugu-jiujian",1);
        skill_level += me->query_skill("zong-jue",1);
        
        if( skill_level < 400 )                              
                return notify_fail("你的修为太潜！\n");
        

message_vision(HIY "情急之间，$N心中如电光石火般闪过了一个念头：\n「独孤九剑」第七剑「破箭式」专破暗器。\n任凭敌人千箭万弩射将过来，或是数十人以各种各样暗器同时攒射，\n只须使出这一招，便能将千百件暗器同时击落。\n$N无余暇再想，长剑倏出，使出「独孤九剑」的「破箭式」，剑尖颤动，向众人的眼睛点去。\n" NOR,me);
//        me->add_temp("apply/attack", skill_level/6);
        me->add_temp("apply/damage", skill_level/6);

        me->clean_up_enemy();
        enemy = me->query_enemy();    
        if( !(int)arrayp(enemy) ) return;
        
        if( member_array(victim,enemy) != -1 )
                enemy -= ({victim});

        weapon=me->query_temp("weapon");
        
        i = sizeof(enemy);
        while(i--)
        {
                target = enemy[i];
                if( enemy[i]->query("kee") < 1 ) continue;              
                write("\n");
                message_vision(HIG+me->query_temp("weapon")->name()+HIG"攻向$n的眼睛！\n"NOR,me,target);
                
                COMBAT_D->do_attack(me,enemy[i],weapon,TYPE_QUICK);
//TYPE_SELFATTACK,action2);
        if( !userp(me) )
        {
         enemy[i]->receive_wound("kee", enemy[i]->query("max_kee")/2);
        }
        }  
        message_vision(HIG"\n$N奋力刺出这数十剑，已然大耗真气，需要好好休息了。\n\n"NOR,me);
//        me->add_temp("apply/attack", -skill_level/6);
        me->add_temp("apply/damage", -skill_level/6);
if(userp(me))
{
        me->add("force",-200);
        me->start_busy(3);
}

        return 1;
}

