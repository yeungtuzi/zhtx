// /obj/boat.c

// #include <room.h>
#include <ansi.h>

inherit ITEM;

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

// int look_room(object me, object env);

void create()
{
        set_name("小船", ({ "boat" }) );
        set_weight(100000);
        set_max_encumbrance(100000000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "野渡无人舟自横\n");
//                set("short", "小船(boat)");
                set("no_cleanup", 1);
        }
}

int is_container() { return 1; }

void init()
{
        add_action("do_in", "in");
}

int do_out()
{
        object me;
        me = this_player();
        if (environment(this_object())) me->move(environment(this_object()));
        message_vision("$N离开$n\n",me,this_object());
        remove_action("do_gogo", "go");
        return 1;
}

int do_in(string arg)
{
        object me, obj;
        me = this_player();
        obj = this_object();
        if ((arg != "小船") &&(arg != "boat") ) 
             return notify_fail("你想进入什么地方?\n");
        if (environment(obj)) {
        message_vision("$N进入$n\n",me,obj);
        me->move(obj);
        add_action("do_gogo", "go");
        add_action("do_out", "out");
        return 1;
        }
}

int valid_gogo(object me, string dir)
{ 
return 1;
}

int do_gogo(string arg)
{
        string dest, mout, min, dir, blk;
        string desc;
        object env, obj, blocker;
        mapping exit;
        mapping block;
        object me;

        me=this_object();
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
                if( objectp(blocker = present(blk, env)) &&  
living(blocker))   
                return notify_fail("这个方向的路被"+ blocker->name() + "挡住了 
。\n");  
        }

        dest = exit[arg];
        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("无法移动。\n");
        if( !env->valid_leave(me, arg) ) return 0;
        if( !valid_gogo(me, arg) ) return 0;
        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;
        if( me->is_fighting() ) {
                mout = "往" + dir + "落荒而逃了.\n";
                min = "狼狈不堪地逃到这里.\n";
        } else {
                mout = "往" + dir + "离开.\n";
                min = "来到这里.\n";
        }
        desc=(string)query("name");
        message( "vision", desc + mout, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
                message( "vision", desc + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
//        if( query("env/brief") )
//  tell_object(this_player(), environment()->query("short") + "\n");
//                else
//                look_room(this_player(),environment());        
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
        do_gogo(directions[random(sizeof(directions))]);
}

int is_vessel()
{ return 1;}

int is_ship()
{ return 1;}


