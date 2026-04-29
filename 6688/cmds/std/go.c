// last change by dongsw 2002

inherit SSERVER;

#include <combat.h>
#include <ansi.h>
#include <dirs.h>


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, mout="", min="", dir, odir, blk;
        string desc;
        object env, obj, blocker,*enemy,target;
        int my_move,your_move,enemy_size,coeff,at;
        mapping exit;
        mapping block;                         
        object * inventory;
        object horse;

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

        if( stringp(env->query_temp("lock_scene")) )
        {
                message_vision(env->query_temp("lock_scene"),me);
                return notify_fail("你无法移动！\n");
        }

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("这个方向没有出路。\n");
                else
                        return 0;
        }
        if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
                if( objectp(blocker = present(blk, env)) &&  living(blocker))   
                        return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 。\n");       
                }

        dest = exit[arg];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n");

        if( !env->valid_leave(me, arg) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;            

        if( !undefinedp(opposite_dirs[arg]) )
                odir = opposite_dirs[arg];
        else
                odir = arg;            

        if(obj->query("no_fight")) 
                if( me->query_condition("quit_delay") ) 
                        return notify_fail("你身负重案，还想躲进休息室？\n"); 

        //战斗中逃跑会判断双方轻功 yeung
        if( me->is_fighting() && arrayp(enemy = me->query_enemy())  )
        {
                enemy_size = sizeof(enemy);
                while( enemy_size-- )
                {
                        if( objectp(target = present(enemy[enemy_size],environment(me))) && !target->is_busy() && living(target) )
                        {
                                my_move = me->query_skill("move");
                                your_move = target->query_skill("move");
                                if( random( my_move + your_move ) < your_move )                              
                                {
                                        message_vision(RED"$N见势不妙转身欲逃，可$n一闪身拦住了$N的去路！\n"NOR,me,target);
                                        me->start_busy(2);
                                        return 1;
                                }           
                                else if( (coeff=your_move-my_move+30) > 0 )                                                               
                                {
                                        message_vision(RED"$N见势不妙转身落荒而逃，$n趁机追上去从后方全力攻击！\n"NOR,me,target);
                                        if( coeff > 60 ) coeff = 60;
                                        me->add_temp("apply/defense",-coeff);                                   
                                        at = coeff/10;
                                        while(at--)
                                        {
                                                if( objectp(me) && me->query("eff_kee") > 0 && environment(me)==environment(target) )
                                                {                                               
                                                        target->add_temp("apply/courage",target->query_wil());
                                                        COMBAT_D->fight(target,me);           
                                                        target->add_temp("apply/courage",0-target->query_wil());                                                  
                                                }
                                                else 
                                                        return 1;
                                        }
                                        me->add_temp("apply/defense",coeff);
                                }       
                        }
                }
        }
//                                                                                   
        if( userp(me) )
        {
                mout="赤身裸体地";
                min="赤身裸体地";

if( objectp(horse = me->query_temp("mounting")) ) {
mout = "骑着" + horse->name();
min = "骑着" + horse->name();
}
else {
                if( me->query_temp("armor/cloth") )
                {
                        mout="身着"+me->query_temp("armor/cloth")->name();
                        min="身着"+me->query_temp("armor/cloth")->name();
                }
                if( me->query_temp("armor/waist") )
                {
                        mout="身着"+me->query_temp("armor/waist")->name();
                        min="身着"+me->query_temp("armor/waist")->name();
                }

        }
        }
        if( me->is_fighting() ) {
                mout += "往" + dir + "落荒而逃了。\n";
                min += "从" + odir + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
        } else {
                mout += "往" + dir + "离开。\n";
                min += "从" + odir + "走了过来。\n";
        }                                  

        //modified by yeung 99/02/02
        if(me->query("per")<15){
                if(me->query("gender")=="女性")
                {
                        if(me->query("age")<18) desc="丑丫头" ;
                        if(me->query("age")>=18&&me->query("age")<50) desc="丑姑娘";
                        if(me->query("age")>=50) desc="丑老太婆";
                }
                else if(me->query("gender")=="男性")
                {
                        if(me->query("age")<18) desc="丑男孩";
                        if(me->query("age")>=18&&me->query("age")<50)desc="丑汉子";
                        if(me->query("age")>=50) desc="糟老头子";
                }
                if(me->query("gender")=="无性")
                {
                        if(me->query("age")<18) desc="小公公";
                        if(me->query("age")>=18&&me->query("age")<40)desc="忸怩作态的丑汉子";
                        if(me->query("age")>=40) desc="丑老太监";
                }
                else desc=RANK_D->query_per(me);
        }
        else if(me->query("per")<25) desc=RANK_D->query_per(me);
        else 
        {
                if(me->query("gender")=="女性")
                {
                        if(me->query("age")<18) desc="如花少女" ;
                        if(me->query("age")>=18&&me->query("age")<30) desc="俏丽姑娘";
                        if(me->query("age")>=30&&me->query("age")<45) desc="美艳妇人";
                        if(me->query("age")>=45) desc="慈祥老妇人";
                }
                else if(me->query("gender")=="男性")
                {
                        if(me->query("age")<18) desc="清秀少年" ;
                        if(me->query("age")>=18&&me->query("age")<30) desc="英俊男子";
                        if(me->query("age")>=30&&me->query("age")<50) desc="潇洒男子";
                        if(me->query("age")>=50) desc="清矍老者";
                }
                else if(me->query("gender")=="无性")
                {
                        if(me->query("age")<18) desc="美貌少年" ;
                        if(me->query("age")>=18&&me->query("age")<30) desc="俊俏公公";
                        else    desc="老公公";
                }
                else desc=RANK_D->query_per(me);
        }
        message( "vision", "一位"+desc + mout, environment(me), ({me}) );

//      to be sure about the sleep_room ;dao
        if(obj->query("sleep_room")) 
                if( obj->valid_enter(me) < 0 ) return 1; 
        if(obj->query("no_faint")) {
                object * inv;
                int i;
                inv = all_inventory(me);
                for( i=0;i<sizeof(inv);i++) {
                        if( inv[i]->is_character() ) 
                                return notify_fail("你不能背着"+inv[i]->query("name")+"进去!\n");
                }
        }       
        if( me->move(obj) ) {
                me->remove_all_enemy();
                message( "vision", desc + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                if( objectp(horse) )
                horse->move(obj);
                if( me->query_condition("quit_delay") && random(me->query_kar())<10 )                 
                        CHANNEL_D->do_channel(me,"rumor","听说"+me->query("name")+"现在躲到了"+obj->query("short")+"。");
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions,cmd;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}


