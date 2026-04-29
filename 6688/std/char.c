// char.c


#define SAVE_INT 300

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;  
inherit F_TRIGGER;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FAMILY;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;
nosave int save_flag,save_tick;

void create()
{
        seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

int raw_set_heart_beat(int flag)
{
        return set_heart_beat(flag);
}

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
        seteuid(getuid(this_object()));

        if( clonep(this_object()) ) {
                set_heart_beat(1);
                tick = 5 + random(10);

                //added by yeung
                save_tick = SAVE_INT;
                save_flag = 0; //第1,2,3次保存原始文件,第4次保存备份                
                
                enable_player();

                CHAR_D->setup_char( this_object() );
        } else
                // Since most npc are only cloned once and only cloned again after
                // the previous one was killed and the room resets, keeping the
                // master copy of characters is just wasting memory. So ... :P
                // By Annihilator(11/11/95)
                // 这大概就是NPC长期不碰就不在内存里面的原因吧. :)
                // 如果不清倒是占点内存,不过也解决很多问题.
                // 还是根据机器的情况取舍吧. 
                // By yeung(99/07/21)
                        
                call_out( "clean_up", 5 );
}

void heart_beat()
{
        int wimpy_ratio, cnd_flag;
        mapping my;
        string wimpy_cmd;
        object ob,link_ob,weap;
        int con_eff;

          if( userp(this_object()))
        {
                  clear_cmd_count();
                save_tick--;
                if( save_tick <= 0 )
                {
                        save_flag++;
                        if( save_flag > 4 ) save_flag = 0;
                        if( save_flag != 4 )
                        {
                                tell_object(this_object(),"自动存盘...");
                                this_object()->save();
                                if( objectp(link_ob=(this_object())->query_temp("link_ob")) )
                                      link_ob->save_back();                   
                                tell_object(this_object(),"完毕.\n");
                                this_object()->update_couple_faith();
                        }
                        else
                        {
                                tell_object(this_object(),"自动备份数据...");
                                this_object()->save_back();
                                if( objectp(link_ob=(this_object())->query_temp("link_ob")) )
                                        link_ob->save_back();
                                tell_object(this_object(),"完毕.\n");
                        }
                        save_tick = SAVE_INT;
                }
        }

        my = query_entire_dbase();

//      delete_temp("command_count");

        // If we are dying because of mortal wounds?
        if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0) {
                if( !userp(this_object()) && this_object()->query("id")=="wolf dog" )
                        CHANNEL_D->do_channel(this_object(), "sys", sprintf("[DEBUG] mortal: eff_kee=%d eff_sen=%d eff_gin=%d", my["eff_kee"], my["eff_sen"], my["eff_gin"]));
                remove_all_enemy();
                die();
                return;
        }

        // If we're dying or falling unconcious?
        if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0 || my["force"]<0 || my["mana"]<0 || my["atman"]<0 )
        {
                if( !userp(this_object()) && this_object()->query("id")=="wolf dog" )
                        CHANNEL_D->do_channel(this_object(), "sys", sprintf("[DEBUG] uncon: kee=%d sen=%d gin=%d force=%d mana=%d atman=%d", my["kee"], my["sen"], my["gin"], my["force"], my["mana"], my["atman"]));
                remove_all_enemy();
                if( !living(this_object()) ) die();
                else unconcious();
                return;
        }

        //年龄很小的时候,心跳会比较快一点.
        con_eff = (30-this_object()->query("age"))/4;
        if( con_eff < 1 ) con_eff = 1;              
        if( con_eff > 4 ) con_eff = 4;              


        // Do attack if we are fighting.
        if( is_busy() ) {
                if( !userp(this_object()) && this_object()->query("id")=="wolf dog" )
                        CHANNEL_D->do_channel(this_object(), "sys", sprintf("[DEBUG] busy=%O", query_busy()));
                continue_action();
                // We don't want heart beat be halt eventually, so return here.
                // busy has the highest priority that healing will be susspended.
                return;
        } else {
                // 战斗中意志力影响斗志,意志力决定能坚持到什么时刻 
                // by Yeung
                if( is_fighting() && living(this_object()) )
                {
                        //wil是30能坚持到底,wil是5能坚持到50%   
                        wimpy_ratio = 60 - query_wil()*2;
                        if(!userp(this_object())) wimpy_ratio -= 20;                    
                        if      (       my["eff_kee"] * 100 / my["max_kee"] <= wimpy_ratio
                                ||      my["eff_sen"] * 100 / my["max_sen"] <= wimpy_ratio
                                ||      my["eff_gin"] * 100 / my["max_gin"] <= wimpy_ratio) 
                        {
                                message_vision("$N面上露出惊惶胆怯之色，忍不住大叫一声，转身掩面而逃！\n",this_object());
                                if( objectp(weap=query_temp("weapon")) )
                                {                 
                                        message_vision("铛的一声，$N手中的"+weap->name()+"掉在了地上。\n",this_object());
                                        if( weap->query("no_drop") || !weap->query("value") )
                                                destruct(weap);
                                        else
                                                weap->move(environment(this_object()));                                        
                                }                                                      
                                GO_CMD->do_flee(this_object());  
                        }                                                                       
                        else            
                        // Is it time to flee?
                        if( 
                                intp(wimpy_ratio = (int)query("env/wimpy"))
                        &&      wimpy_ratio > 0
                        &&      (       my["kee"] * 100 / my["max_kee"] <= wimpy_ratio
                                ||      my["sen"] * 100 / my["max_sen"] <= wimpy_ratio
                                ||      my["gin"] * 100 / my["max_gin"] <= wimpy_ratio) )
                        {
                                if(stringp(wimpy_cmd = (string) query("env/save_me!")))
                                        command(wimpy_cmd);
                                else
                                        GO_CMD->do_flee(this_object());
                        }    
                        else
                        {
                                attack();
                                if( random(con_eff) ) attack();                                 
                        }                               
                }
                else
                {
                        attack();
                        if( random(con_eff) ) attack(); 
                }
        }

        if( !this_object() ) return;
        if( !userp(this_object()) ) {
                this_object()->chat();
                // chat() may do anything -- include destruct(this_object())
                if( !this_object() ) return;    
        }

        if( tick--  ) return;
        else
        {
                //年龄很小的时候,心跳会比较快一点.
                 tick = 6 + random(10) - con_eff;
        }       

        cnd_flag = update_condition();

        // If we are compeletely in peace, turn off heart beat.
        // heal_up() must be called prior to other two to make sure it is called
        // because the && operator is lazy :P
        if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
        &&      !is_fighting() 
        &&      !interactive(this_object())) {
                if( environment() ) {
                        ob = first_inventory(environment());
                        while(ob && !interactive(ob))
                                ob = next_inventory(ob);
                }
                if( !ob ) set_heart_beat(0);
        }
        
        if( !interactive(this_object()) ) return;

        // Make us a bit older. Only player's update_age is defined.
        // Note: update_age() is no need to be called every heart_beat, it
        //       remember how much time has passed since last call.
        this_object()->update_age();

        if(query_idle(this_object()) > IDLE_TIMEOUT)
                this_object()->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
        int lvl, invis;

        lvl = wiz_level(this_object());

        if( lvl > wiz_level(ob) ) return 1;
        invis = ob->query("env/invisibility");
        //对隐识
        if( !wiz_level(ob) && !raw_wiz_level(ob) && query_temp("apply/astral_vision") )
                return 1;
                
        if( intp(invis) && (invis > lvl) ) return 0;

        if( ob->is_ghost() ) {
                if( is_ghost() ) return 1;
                if( query_temp("apply/astral_vision") ) return 1;
                return 0;
        }
    return 1;
}

//可以由别的物件来调用     yeung
int fcommand(string custom_cmd)
{
     return command(custom_cmd);
}

//和fy的兼容
int ccommand(string custom_cmd)
{
     return command(custom_cmd);
}

