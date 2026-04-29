/**************************************************************************/
/// $Id: make_bomb.c,v 1.2 2000/12/14 15:21:43 cmy Exp $
/**************************************************************************/
// music.c

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object victim)
{
        string msg0,msg1,msg2;
        object *enemy,weapon;
        int i;
        int enemy_kee,current_kee;
        int enemy_sen,current_sen;
        int enemy_gin,current_gin;
        object obj;

        me->clean_up_enemy();
        enemy = me->query_enemy();
        if( !arrayp(enemy) ) return;        
      
        if( member_array(victim,enemy) != -1) enemy -= ({victim});

        i = sizeof(enemy);

        if(!objectp(present("purpleliuhuang",me))) return notify_fail("你没有紫色硫磺，无法制出紫色火药.\n");
        obj=present("purpleliuhuang",me);
        destruct(obj);
       
        message("sys",MAG"$N掏出一块紫色的硫磺，很快作出了一块紫色火药！\n"NOR,users());                

        if( !me->is_fighting(victim) )
                return notify_fail("火药术只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        if(weapon!=0) return notify_fail("你必须空手才能制作火药\n");

        if(me->query_skill("tie_makeing",1) < 301) return notify_fail("你的鬼斧神工还不到家，无法制作火药。\n");

        if( me->query_skill_mapped("unarmed") != "tie_makeing")
                return notify_fail("你必须首先激发鬼斧神工!\n");

        if( (int)me->query("kee") < 1500 ) return notify_fail("你的气不够！\n");
        if( (int)me->query("gin") < 100 || (int)me->query("sen") < 100 ) return notify_fail("你的精神不够！\n");
        
        if( (int)me->query("force") - (int)me->query("max_force") < 1000 )
                return notify_fail("你的真气不够！\n");

        msg1 = HIW"$N将手中的紫色火药向$n扔去，只听得碰的一声，火药在$n旁边炸开！\n"NOR;
        msg2 = HIR"$n被火药炸飞到天空，哇的一声吐出一口鲜血。\n"NOR;

        while(i--)
        {
           if (enemy[i]->query("kee")<1) continue;
           write("\n");
           message_vision(msg1,me,enemy[i]);
           message_vision(msg2,me,enemy[i]);

           enemy_kee = enemy[i]->query("max_kee");
           current_kee = enemy[i]->query("kee");
           enemy_gin = enemy[i]->query("max_gin");
           current_gin = enemy[i]->query("gin");
           enemy_sen = enemy[i]->query("max_sen");
           current_sen = enemy[i]->query("sen");

           enemy[i]->receive_damage("kee",(int)enemy_kee*0.9);
           enemy[i]->receive_wound("kee",(int)enemy_kee*0.9);
           enemy[i]->receive_damage("gin",(int)enemy_gin*0.9);
           enemy[i]->receive_wound("gin",(int)enemy_gin*0.9);
           enemy[i]->receive_damage("sen",(int)enemy_sen*0.9);
           enemy[i]->receive_wound("sen",(int)enemy_sen*0.9);

        }


        me->receive_damage("kee",1000);        
        me->receive_damage("sen",100); 
        me->receive_damage("gin",100);               
        me->add("force",-1000);
        return 1;
}

