// /obj/npc/wolfguard.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"啸天"+HIW"犬"NOR, ({ "celestial dog", "dog"}));
        set("long", YEL"时代进步了，狗狗也跟上潮流不和二郎神混了，真是这一只吗？\n看起来满可爱的，没有想象中那么可怕哦！\n"NOR);
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
        
        set_name(YEL"啸天"+HIW"犬"NOR, ({ "celestial dog", "dog"}));
        set("long", YEL"时代进步了，狗狗也跟上潮流不和二郎神混了，真是这一只吗？\n看起来满可爱的，没有想象中那么可怕哦！\n"NOR);
        set("age",who->query("age"));
        set("gender", "男性");
        set("nickname", HIR"食日天狗"NOR);
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "尾巴", "脖颈", "小腹", "爪子" }) );
        set_skill("dodge", mdodge);
        set_skill("parry", mparry);
        set_skill("pyrobat-steps", mdodge);
        set_skill("celestrike", mparry);
        set_skill("force", mdodge+mparry);
        set_skill("strike", mdodge+mparry);
        set_skill("tenderzhi", mdodge+mparry);

        map_skill("parry", "celestrike");
        map_skill("dodge", "pyrobat-steps");
        map_skill("strike", "celestrike");
        prepare_skill("strike", "celestrike");


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
        message_vision(YEL"不知从那里窜出一只$N"+YEL"，冲着$n摇了摇尾巴，显然已然认定了今世的主人。\n" NOR, me, who );
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if( !who->is_killing(enemy[i]) )
                                fight_ob(enemy[i]);
                        else
                                kill_ob(enemy[i]);
                        enemy[i]->kill_ob(this_object());
                        enemy[i]->remove_charge();
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
        message_vision(YEL"$N"+YEL"惨嚎了一声，化作一片烟云消散了。\n" NOR,this_object());
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


