#include <ansi.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":                "北",
        "south":                "南",
        "east":                 "东",
        "west":                 "西",
        "northup":              "北边",
        "southup":              "南边",
        "eastup":               "东边",
        "westup":               "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":             "东边",
        "westdown":             "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":                   "上",
        "down":                 "下",
        "out":                  "外",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string dest, mout="", min="", dir, blk;
        string desc;
        object env, obj, blocker;
        mapping exit;
        mapping block;                         

        if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");

        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");

        env = environment(me);
        if(!env) return notify_fail("你哪里也去不了。\n");

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

//                                                                                   
        if( userp(me) )
        {
                mout="赤身裸体地";
                min="赤身裸体地";

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
        if( me->is_fighting() ) {
                mout += "往" + dir + "落荒而逃了。\n";
                min += "跌跌撞撞地跑了过来，模样有些狼狈。\n";
        } else {
                mout += "往" + dir + "离开。\n";
                min += "走了过来。\n";
        }                                  

        if(me->query("per")>=10&&me->query("per")<=15){
                if(me->query("gender")=="女性"){
                        if(me->query("age")<18) desc="丑丫头" ;
                        if(me->query("age")>=18&&me->query("age")<40) desc="丑姑娘";
                        if(me->query("age")>=40) desc="丑老太婆";
                        }
                if(me->query("gender")=="男性"){
                        if(me->query("age")<18) desc="丑男孩";
                        if(me->query("age")>=18&&me->query("age")<40)desc="丑汉子";
                        if(me->query("age")>=40) desc="丑老头";
                        }
		if(me->query("gender")=="无性"){
                        if(me->query("age")<18) desc="小公公";
                        if(me->query("age")>=18&&me->query("age")<40)desc="公公";
                        if(me->query("age")>=40) desc="老公公";
                        }
                }
        if(me->query("per")>15&&me->query("per")<25) desc=RANK_D->query_per(me);
        if(me->query("per")>=25){
                                if(me->query("gender")=="女性") desc="美丽"+RANK_D->query_per(me);
                                else desc="英俊"+RANK_D->query_per(me);
                               }
        message( "vision", "一位"+desc + mout, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
                message( "vision", desc + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

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



