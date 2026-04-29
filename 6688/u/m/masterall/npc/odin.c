#include <ansi.h>
inherit NPC;

//没有敌人而离去
void leave();
//杀掉敌人而离去
void depart();

//斩铁剑
void zantetsuken(object victim);

object me=this_object();

void create()
{
        set_name(HIB"奥丁"NOR, ({ "odin","ao ding"}) );
        set("long",BLK@LONG
胯下骑一匹神驹斯内普尼尔不知踏过多少沾满血迹的战土。
手中一柄锈迹斑斑的黑色铁剑让多少邪魔丧命于必杀斩铁剑
下。大神奥丁，最终的奥秘…………
LONG NOR
         );

        set("max_gin", 5000);
        set("max_kee", 5000);                    
        set("max_sen", 5000);
        set("max_force",5000); 
        set("max_mana",10000);
        set("mana",20000);
        set("max_atman",5000);
        set("atman",10000);
        set("force",10000);
        set("force_factor",500);     
        set("mana_factor",500);     
        set("combat_exp",29999999);
        set("cor",10);
        set("cps",500);   
        set("spi",500);
        set("per",500);
        set("str",500);
        set("age",1000);

        set_temp("apply/astral_vision", 1);


        set_temp("apply/damage",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_vs_force",500);
        set_temp("apply/attack",500);
        set_temp("apply/defense",500);
        set_temp("apply/dodge",500);
        set_temp("apply/parry",500);


        setup();
        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}                          

void init()
{
        return;
}
                             
int killed_enemy(object ob)
{
        depart();
}                 
                     
//奥丁判断对方是否玩家，如果是NPC则杀死并离去。如果无对手，离去。
int chat()
{       
        object *enemys,victim;
        int i;
        
        clean_up_enemy();
        enemys = query_enemy();
        i = sizeof(enemys);
        //不对玩家使用
        while(i--)
        {
                if( userp(enemys[i]) )
                {
                        remove_enemy(enemys[i]);
                        enemys[i]->remove_enemy(this_object());
                }                                            
        }       
        //对NPC使用必杀斩铁剑
        clean_up_enemy();
        enemys = query_enemy();
        
        i = sizeof(enemys);
        
        if( !i ) me->leave();
        
        //随机挑一个对手吧
        victim = enemys[random(i)];     
        me->zantetsuken(victim);
}       


void die()
{
}

void depart()

{
        message("vision", HIR"\n\n奥丁收缰，垂剑，一滴一滴的血从斩铁剑上滴下，混在雨里\n\n"NOR, environment());
        message("vision", YEL"\n\n奥丁催动胯下斯内普尼尔，消失在雨中天际边………………\n\n"NOR, environment());
                destruct(this_object());

}

void zantetsuken(object victim)
{
                if( userp(victim) ) {me->leave();return;}
        if( environment() ) {
        message("vision", BLK"\n\n阴云密布，细雨朦胧，"NOR + HIW"一道闪电撕破了天际——————\n\n", environment());
        message("vision", BLU"\n奥丁骑着他的爱马出现，手握斩铁剑，一带马缰，如疾风般冲向" + victim->query("name") + "\n", environment());
        message("sound", HIW"\n       斩\n\n"NOR, environment());
        message("sound", HIR"\n                  铁\n\n"NOR, environment());
        message("sound", HIY"\n                             剑\n\n"NOR, environment());
        message("sound", HIC"\n 将"+ victim->query("name") +"一下斩为两半！\n\n"NOR, environment());
                victim->die();
        }
                me->depart();
}

void leave()

{
        message("vision", YEL"\n\n奥丁一扭头，催动胯下斯内普尼尔，消失在雨中天际边………………\n\n"NOR, environment());
                destruct(this_object());

}

