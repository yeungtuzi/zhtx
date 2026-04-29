// /obj/npc/wolfguard.c

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
        set_name(HIW"九天"+HIY"雷鹏"NOR, ({ "ninesky roc", "roc"}));
        set("long", HIY"一只体态极为魁梧的巨鸟，好似极为臃肿笨重，\n但飞翔之时却轻盈无比，就连号称轻功天下第一的“司空摘星”都自愧不如。\n"NOR);
        setup();
}

void invocation(object who)
{
        int i;
        object *enemy,me,ob,*inv;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname, err;
        int temp,add_skill1,add_skill2,mdodge,mparry,mskill; 
        mdodge = who->query_skill("dodge",1); 
        mparry = who->query_skill("parry",1); 
        mskill = who->query_skill("leardership", 1)+1;

        
        me = this_object();
        ob = who;
        if( !objectp(ob) ) return;
        
        set_name(HIW"九天"+HIY"雷鹏"NOR, ({ "ninesky roc", "roc"}));
        set("long", HIY"一只体态极为魁梧的巨鸟，好似极为臃肿笨重，\n你但飞翔之时却轻盈无比，就连号称轻功天下第一的“司空摘星”都自愧不如。\n"NOR);
        set("age",who->query("age"));
        set("gender", "男性");
        set("nickname", HIY"晚月庄护庄神鸟"NOR);
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "尾巴", "左翼", "右翼", "爪子" }) );
 //       set("verbs", ({ "poke" , "claw" }) );
        set_skill("dodge", mdodge);
        set_skill("parry", mparry);
        set_skill("stormdance", mdodge);
        set_skill("snowwhip", mparry);
        set_skill("force", mdodge+mparry);
        set_skill("strike", mdodge+mparry);
        set_skill("mo-zhang-jue", mdodge+mparry);

        map_skill("parry", "snowwhip");
        map_skill("dodge", "stormdance");
        map_skill("strike", "mo-zhang-jue");
        prepare_skill("strike", "mo-zhang-jue");


        set("combat_exp",who->query("combat_exp"));


        hp_status = ob->query_entire_dbase();

        me->set("str", mskill/5+1);
        me->set("int", mskill/5+1);
        me->set("con", mskill/5+1);
        me->set("per", mskill/5+1);
        me->set("cor", mskill/5+1);
        me->set("cps", mskill/5+1);  
        me->set("max_kee", hp_status["max_kee"]*2);
        me->set("eff_kee", hp_status["max_kee"]*2);
        me->set("kee",     hp_status["kee"]*2);
        me->set("max_gin",     hp_status["gin"]*2);
        me->set("eff_gin",     hp_status["gin"]*2);
        me->set("gin", hp_status["gin"]*2);
        me->set("max_sen",     hp_status["max_sen"]*2);
        me->set("eff_sen",     hp_status["eff_sen"]*2);
        me->set("sen",     hp_status["sen"]*2);
        me->set("force",     hp_status["force"]*2);
        me->set("max_force",     hp_status["max_force"]*2);
        me->set("force_factor",     hp_status["force_factor"]*4);
        me->set("combat_exp",hp_status["combat_exp"]);

        setup();

        set("bellicosity",who->query("bellicosity"));
        set_temp("apply",who->query_temp("apply"));     
        
        who->clean_up_enemy();
        enemy = who->query_enemy();
        message_vision(HIY"一只神鸟从天而降，有似天神般守护在$N的身旁！\n" NOR, who );
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if( !who->is_killing(enemy[i]) )
                                fight_ob(enemy[i]);
                        else
                                kill_ob(enemy[i]);
                        enemy[i]->kill_ob(this_object());
                        enemy[i]->remove_charge();
/*
                        if( random(enemy[i]->query_cps()) < who->query_skill("mysterrier",1)/8 )                        
                        {
                                tell_object(enemy[i],"你眼前一花，失去了攻击目标。\n");
                                enemy[i]->charge_ob(this_object());
                        }
*/
                                enemy[i]->charge_ob(this_object());
        if(random(3)>0){
        message_vision(HIC"$N"+HIC"在$n上空盘旋数周，突然一道霹雳向$n头顶直击而去，随后传出的炸雷使天地为之变色！！\n" NOR,me,enemy[i]);
                        if (random(enemy[i]->query_cps()) < who->query_skill("iceforce",1)/8 ){
                                enemy[i]->receive_wound("kee",who->query_skill("iceforce",1)*2);
//                                enemy[i]->set("title", HIW"坏事做多被雷劈"NOR);

        message_vision(HIW"\n$n惊呼“吾命休亦！！”一道闪电在$n头上炸开，迸发出绚丽的光芒，\n雷声过后$n发觉自己的头发一根不剩，缕缕的冒着一股烤焦皮毛的烟气！！\n" NOR, me,enemy[i] );
                                COMBAT_D->report_status(me,enemy[i],1); 
                           }else{
        message_vision(HIG"\n$n心想自己为人堂堂正正，上无愧于天地，下无愧于黎民，即便是天谴，也由不得$N你来操这份闲心！！\n" NOR, me,enemy[i] );
                           }
                       }
                                         


                }
        }
        set_leader(who);
        set("possessed",who);
        who->add_temp("myguard",1);       
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
int chat()
{
        object owner;

        if( !is_fighting() || !objectp(owner=this_object()->query("possessed"))
                || !owner->is_fighting() || environment(this_object()) != environment(owner) )
        {
                                call_out("leave", 1);
        }
        return 1;
}

void die()
{
        call_out("leave",1);
}

void unconcious()
{
        die();
}

void leave()
{
        object owner;
        remove_call_out("leave");
        message_vision(YEL"$N"+YEL"悲鸣一声直入九霄，瞬间化作万道金光，消散得无影无踪。\n" NOR,this_object());
        if( objectp(owner = query("possessed")) )
        {
                owner->add_temp("myguard",-1);                
        }
        destruct(this_object());
}

int defeated_enemy(object victim)
{
        object owner;
        if( objectp(owner = query("possessed")) )
        {
                owner->defeated_enemy(victim);
                COMBAT_D->winner_task(owner,victim);
        }
}                                          

int killed_enemy(object victim)
{
        object owner;
        if( objectp(owner = query("possessed")) )
        {
                COMBAT_D->killer_reward(owner,victim);
        }
} 


