// bow.c 远程攻击的实现
// Create by dongsw@zhtx2 

inherit ITEM;
#include <dirs.h>

void create()
{
        set_name("铁弓", ({ "iron bow" ,"bow" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把铁弓。\n");
                set("value", 100);
                set("material", "iron");
        }
        setup();
}

void init()
{
        add_action("do_shoot","shoot");
}

int do_shoot(string arg)
{
        int num, i, j, t;
        string dir, npcid, nextroom, odir, ddir;
        object me, room, *inv, target, ob;
        string *roomdirs, roompath, obname, tname;
        mapping exits;
        
        me = this_player();
        ob = this_object();

        obname = ob->query("name");

        
        if(!arg) return notify_fail("你要怎么射？\n");
        
        if( sscanf(arg, "%s %d %s", dir, num, npcid )!=3 )
        return notify_fail("您输入的命令的格式不对。\n正确的格式为："
                           "shoot<空格>方向<空格>距离<空格>目标\n");
        
        if(num < 3 || num > 5) return notify_fail("你的弓箭符合不了你所要求的射程。\n");

        ddir = default_dirs[dir];
        odir = opposite_dirs[dir];
        
        message_vision("$N拿着"+obname+"冲着"+ddir+"射了一箭！\n",me);
        
        //这里就是判断出口的东东了
        for(i=0; i<num; i++)
        {
                if (!roompath) roompath = base_name(environment(me));
                room = load_object(roompath);
                exits = room->query("exits");
                
                roomdirs = keys(exits);
                for(j=0; j<sizeof(roomdirs); j++)
                {
                        
                        if ( roomdirs[j] == dir) 
                        {
                                if( room != environment(me) )
                                {
                                        tell_room(room,"一只箭“噌”的一声向"+ddir+"飞了过去，吓的惊你出了一身冷汗！\n");
                                }
                                roompath = exits[roomdirs[j]];
                                t++;
                                break;
                        }
                        else continue;
                }
        }
        
        //这里以后就是实施攻击了
        if( t < num ) return notify_fail("你射的箭射在墙上拉！\n");
        
        room = load_object(roompath);
        target = present(npcid, room);
        
        if(!target)
        {
                tell_object(me,"那里没有那个人，箭射在地上拉！\n");
                tell_room(room,"“噌”的一声一只箭从"+odir+"射在了离你不远的地上，吓得你出了一身冷汗！\n");
                return 1;
        }
        else if( !living(target))
        {
                tell_object(me,"你射的那个东西不是活物，白射拉！\n");
                return 1;
        }               
        else
        {
                tname = target->query("name");
                tell_room(room,"“噌”的一声一只箭从"+odir+"飞了过来，射向了"+tname+"。\n");
        }
        
        switch(random(4))
        {
                case 0:
                {
                        target->receive_wound("kee",1000);
                        tell_room(room,tname+"被箭“噌”等一下射出了个血窟窿!\n");
                        tell_object(me,"你听见"+ddir+"传来一声惨叫，看来是射中了！\n");
                        return 1;
                }
                case 1:
                {
                        tell_room(room,tname+"身手甚是敏捷，躲了过去!\n");
                        tell_room(room,tname+"直纳闷？？？？？谁在偷袭我？？？？\n");
                        tell_object(me,ddir+"什么动静都没有，看来是射歪了！\n");
                        return 1;
                }
                case 2:
                {
                        tell_room(room,tname+"身手甚是敏捷，躲了过去!\n");
                        tell_room(room,tname+"似乎发现了什么，直着朝"+odir+"跑了过去!\n");
                        target->move(environment(me));
                        tell_object(me,ddir+"什么动静都没有，看来是射歪了！\n");
                        message_vision("$N冲了过来！！！\n",target);
                        message_vision("$N冲着$n嚷到：好小子，你敢偷袭我？？去死吧你！\n",target,me);
                        target->set_leader(me);
                        target->kill_ob(me);
                        return 1;
                }
                case 3:
                {
                        target->receive_wound("kee",1000);
                        tell_room(room,tname+"被箭“噌”等一下射出了个血窟窿!\n");
                        tell_room(room,tname+"似乎发现了什么，直着朝"+odir+"跑了过去!\n");
                        target->move(environment(me));
                        tell_object(me,"你听见"+ddir+"传来一声惨叫，看来是射中了！\n");
                        message_vision("$N冲了过来！！！\n",target);
                        message_vision("$N冲着$n嚷到：好小子，你敢偷袭我？？去死吧你！\n",target,me);
                        target->set_leader(me);
                        target->kill_ob(me);
                        return 1;
                }
                
        }
        
        return 1;
}

