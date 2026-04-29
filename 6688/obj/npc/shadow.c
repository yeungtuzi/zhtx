//shadow.c
// by yeung

#include <ansi.h>

inherit NPC;

void create()
{
        set_name( "影子" , ({ "shadow" }) );
        set("long", "武林高手的分身。\n");
        set("mirror_shadow",1);
        setup();
}

void init()
{
        object owner;
        
        add_action("do_app","apprentice");
        add_action("do_look","look");   
        add_action("do_pk","pk");               

        if( objectp(owner = query("possessed")) && owner == this_player() )
        {
                return;
        }              
        
        ::init();
}

int do_app(string arg)
{                   
        object owner,me;        
        int j;
        if(!arg) return 0;
        sscanf(arg,"%s %d",arg,j);
                               
        me = this_player();
                       
        if( id(arg) && objectp(owner=this_object()->query("possessed")) && userp(owner) )
        {
                write("玩家不能互相拜师,除非他开山立派.\n");                           
                return 1;
        }                
        return 0;
}       

int do_pk(string arg)
{                   
        object owner,me;
        int j;            
        if(!arg) return 0;        
        sscanf(arg,"%s %d",arg,j);
                       
        me = this_player();
                               
        if( id(arg) && objectp(owner=this_object()->query("possessed")) )
        {
                load_object("/cmds/std/pk");
                "/cmds/std/pk"->main(me,owner);
                return 1;
        }                
        return 0;
}       


int do_look(string arg)
{                   
        object owner,me;
        int j;            
        if(!arg) return 0;        
        sscanf(arg,"%s %d",arg,j);
                       
        me = this_player();
                               
        if( objectp(owner=this_object()->query("possessed")) && owner->id(arg) )
        {
                load_object("/cmds/std/look");
                return ("/cmds/std/look"->main(me,owner));
        }                
        return 0;
}       

int chat()
{
        object owner;

        if( !is_fighting() || !objectp(owner=this_object()->query("possessed"))
                || !owner->is_fighting() || environment(this_object()) != environment(owner) )
        {
                                //remove_call_out("leave");
                                call_out("leave", 1);
               //owner->add_temp("mystshadow",-1);
               //message_vision(HIG"一阵清风吹过，仿佛一场惊梦，化身无影无踪。\n" NOR,this_object());
               //destruct(this_object());
        }
        return 1;
}

void leave()
{
        object owner;
        remove_call_out("leave");
        message_vision(HIG"一阵清风吹过，仿佛一场惊梦，化身无影无踪。\n" NOR,this_object());
        if( objectp(owner = query("possessed")) )
        {
                add_temp("apply/astral_vision", -1);
                owner->add_temp("mystshadow",-1);                
        }
        destruct(this_object());
}

void invocation(object who)
{
        int i;
        object *enemy,me,ob,*inv,weap,myweap;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname, err;
        int temp,add_skill1,add_skill2; 
        
        me = this_object();
        ob = who;
        if( !objectp(ob) ) return;
        
        set_name( who->query("name") , who->parse_command_id_list() );
        set("age",who->query("age"));
        set("gender",who->query("gender"));
        set("long",who->query("long"));
        set("nickname",who->query("nickname"));
        set("title",who->query("title"));

        set("combat_exp",who->query("combat_exp"));

        // need to clone owner's exp,skills and all inventory here

        if ( mapp(skill_status = me->query_skills()) ) {
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
        }

        if ( mapp(skill_status = ob->query_skills()) ) {

                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                    me->set_skill(sname[i],skill_status[sname[i]]*3/4);
//继续削弱,masterall
                }
        }

        /* delete and copy skill maps */
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {

                        me->map_skill(mname[i], map_status[mname[i]]);
                }
        }

        /* delete and copy skill prepares */

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pname[i]);
                }
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("per", hp_status["per"]);
        me->set("cor", hp_status["cor"]);
        me->set("cps", hp_status["cps"]);                
        me->set("max_force", hp_status["max_force"]);
        me->set("force",     hp_status["force"]);
//        me->set("force_factor",     hp_status["force_factor"]);
//开始削弱mirror的enforce
        me->set("force_factor",    0);
        me->set("combat_exp",hp_status["combat_exp"]*3/4);

        setup();

        //不复制武器,否则有BUG,但是damage和主人一样
       
        if( objectp(weap=who->query_temp("weapon")) )
        {
                myweap = carry_object("/obj/weapon/"+weap->query("skill_type"));
                if( objectp(myweap) )
                {
                        myweap->set_name( weap->query("name") , ({ weap->query("id") }) );
                        myweap->set("value",0);
                        myweap->set("no_get",1);
                        myweap->set("no_give",1);
                        myweap->set("weapon_prop/damage",0);
                        myweap->wield();
                }
        }

        //LPMUD除了简单数据类型之外,其他的都是传指针调用
        //所以不能对shadow的temp_dbase做修改.
                
        //这里如果用set_temp,就会造成perform者也有astral_vision
        //只能现在add,影子消失的时候减
        set("bellicosity",who->query("bellicosity"));
        set_temp("apply",who->query_temp("apply"));     
        add_temp("apply/astral_vision", 1);
        
        who->clean_up_enemy();
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if( !who->is_killing(enemy[i]) )
                                fight_ob(enemy[i]);
                        else
                                kill_ob(enemy[i]);
                        enemy[i]->kill_ob(this_object());
                        enemy[i]->remove_charge();
                        
//                        if(enemy[i]->query("family/family_name") == "唐门" &&
/*
                          ( random(enemy[i]->query_skill("mantian-huayu",1)) >= me->query_skill("mysterrier",1)/2 ||
                           random(enemy[i]->query_skill("tiannv-sanhua",1)) >= me->query_skill("mysterrier",1)/2))&&
::                           random(enemy[i]->query_skill("throwing",1)) >= me->query_skill("dodge",1)/2)
                        {
//                                message_vision(HIR"\n$N一支飞镖出手，毁幻影于无形！\n"NOR,enemy[i]);
                                this_object()->leave2();
                                return;
                        }
*/
                        
//                        if( random(enemy[i]->query_cps()) < who->query_skill("mysterrier",1)/16 )                        
//减弱shadow discharge的效果 masterall
                        if( random(enemy[i]->query_cps()) < who->query_skill("mysterrier",1)/80 )                        
                        {
                                tell_object(enemy[i],"你眼前一花，失去了攻击目标。\n");
                                enemy[i]->charge_ob(this_object());
                        }
                }
        }
        set_leader(who);
        set("possessed",who);
        who->add_temp("mystshadow",1);       
}

void leave2()
{
        object owner;
        remove_call_out("leave2");
        add_temp("apply/astral_vision", -1);
        message_vision(HIC "如同击碎惊梦，化身无影无踪。\n" NOR,this_object() );
        if( objectp(owner = query("possessed")) )
        {
                owner->add_temp("mystshadow",-1);                
        }
        destruct(this_object());
}

void die()
{
        call_out("leave2",1);
}

void unconcious()
{
        die();
}

varargs receive_damage(string type,int damage,object killer)
{
        die();
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
