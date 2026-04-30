// /obj/npc/wolfguard.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIC"七"+HIM"彩"+HIY"金凤"NOR, ({ "phoenix"}));
        set("long", HIC"这难道就是传说中晚月庄的护庄神鸟——七彩金凤？\n她的体态卓约，气质高贵，已非凡间禽类所能比，\n浑身上下散发着金黄色的光芒，使你不敢去看她，却又忍不住多看两眼。\n"NOR);
        setup();
}

void invocation(object who)
{
        int i;
        object *enemy,me,ob,*inv;
        mapping hp_status, skill_status, map_status, prepare_status;
        // 2026-04-30: unused variable commented out
        // string *sname, *mname, *pname, err;
        int temp,add_skill1,add_skill2,mdodge,mparry,mskill; 
        mdodge = who->query_skill("dodge",1); 
        mparry = who->query_skill("parry",1); 
        mskill = who->query_skill("leardership", 1)+1;

        
        me = this_object();
        ob = who;
        if( !objectp(ob) ) return;
        
        set_name(HIC"七"+HIM"彩"+HIY"金凤"NOR, ({ "golden phoenix", "phoenix"}));
        set("long", HIY"这难道就是传说中晚月庄的护庄神鸟——七彩金凤？\n她的体态卓约，气质高贵，已非凡间禽类所能比，\n浑身上下散发着金黄色的光芒，使你不敢去看她，却又忍不住多看两眼。\n"NOR);
        set("age",who->query("age"));
        set("gender", "女性");
        set("nickname", HIM"晚月庄护庄神鸟"NOR);
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "尾巴", "左翼", "右翼", "爪子" }) );
 //       set("verbs", ({ "poke" , "claw" }) );
        set_skill("dodge", mdodge);
        set_skill("parry", mparry);
        set_skill("stormdance", mdodge);
        set_skill("snowwhip", mparry);
        set_skill("force", mdodge+mparry);
        set_skill("finger", mdodge+mparry);
        set_skill("tenderzhi", mdodge+mparry);

        map_skill("parry", "snowwhip");
        map_skill("dodge", "stormdance");
        map_skill("finger", "tenderzhi");
        prepare_skill("finger", "tenderzhi");


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
        me->set("force_factor",     hp_status["force_factor"]*2);
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
        if(random(3)>1){
        message_vision(HIC"$N"+HIC"全身爆发出闪耀的光芒，方圆数丈瞬间极光环绕，已然超过了时空，跨越了极限！！\n" NOR, me );
                        if (random(enemy[i]->query_cps()) < who->query_skill("iceforce",1)/8 ){
                                enemy[i]->receive_damage("gin",who->query_skill("iceforce",1));
                                enemy[i]->receive_damage("sen",who->query_skill("iceforce",1));
        message_vision(YEL"\n$n被$N"+YEL"散发出的光芒刺得两眼发黑，顿时有些心神不定！！\n" NOR, me,enemy[i] );
                           }else{
        message_vision(HIR"\n$n的瞳孔中爆发出一阵阵精芒，丝毫不把$N"+HIR"放在心上！！\n" NOR, me,enemy[i] );
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


