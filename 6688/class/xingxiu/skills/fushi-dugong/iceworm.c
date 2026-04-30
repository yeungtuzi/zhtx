// /obj/npc/wolfguard.c

#include <ansi.h>
void use_poison();

inherit NPC;

void create()
{
        set_name(HIG"碧"+HIR"血"+HIW"寒蚕"NOR, ({ "bixue hancan"}));
        set("long", HIC"这蚕虫纯白如玉，微带青色，比寻常蚕儿大了一倍有余，便似一条蚯蚓，身子透明直如水晶。\n"NOR);
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
        
        set_name(HIG"碧"+HIR"血"+HIW"寒蚕"NOR, ({ "bixue hancan"}));
        set("long", HIC"这蚕虫纯白如玉，微带青色，比寻常蚕儿大了一倍有余，便似一条蚯蚓，身子透明直如水晶。\n"NOR);

        set("nickname", HIG"百毒之首"NOR);
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "尾巴", "前萼", "爪子" }) );
 //       set("verbs", ({ "poke" , "claw" }) );
        set_skill("dodge", mdodge);
        set_skill("parry", mparry);
        set_skill("stormdance", mdodge);
        set_skill("snowwhip", mparry);
        set_skill("force", mdodge+mparry);
        set_skill("finger", mdodge+mparry);
        set_skill("xingxiu-duzhang", mdodge+mparry);

        map_skill("parry", "xingxiu-duzhang");
        map_skill("dodge", "lingboweibu");
        map_skill("strike", "xingxiu-duzhang");
        prepare_skill("strike", "xingxiu-duzhang");


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
        message_vision(HIC"便在此时，忽觉得一阵寒风袭体，只见西角上一条火线烧了过来，同时寒气越来越盛，\n只见草丛枯焦的黄线移向木鼎，却是一条蚕虫，它警惕着环顾了四周一眼，\n顺着神鼎找到了自己的主人——$N！\n"NOR, who );
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
        if( enemy[i]->query_condition("super_poisons") ) return;
        message_vision(HIB"$N头部的毒囊瞬间鼓胀，一股强烈的腥臭之气向$n激射而出！\n"NOR, me,enemy[i]  );
        if( random(me->query("combat_exp")) > (int)enemy[i]->query("combat_exp")/2 )
        {
        message_vision(HIG"$n躲闪不及，被喷了个满脸花，顿时哭天抢地般嘶嚎了起来 ！\n"NOR, me,enemy[i]  );
                enemy[i]->apply_condition("super_poisons", 20+random(20));
        }
        else       
        {
        message_vision(HIY"$n情知不妙顺势一躲，刚才所立之处已变得焦黑一片！\n"NOR, me,enemy[i]  );
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
        message_vision(HIB"$N"+HIB"惨叫一声，化做了一滩血水，嘶嘶的冒着腥臭之气。\n" NOR,this_object());
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



