// fly.c 
//by masterall
//九阴神功召唤神雕.

#include <ansi.h>

inherit F_SSERVER;

int carrying;

int exert(object me, object target)
{
  object *inv;
  object ob;

        if( me->query_skill("jiuyin-shengong",1) < 250) 
                return notify_fail("你九阴神功修为不够，不能召唤神雕！\n");
        if (objectp(ob = present("shui jing",me) ) )
                return notify_fail("你不能在挖宝的时候飞来飞去的，不怕找到的宝物被神仙收走了？\n");  
        if( me->is_fighting() )
                return notify_fail("战斗中无法召唤神雕！\n");
        if( me->is_busy() )
                return notify_fail("你正忙着呢，还是省省吧，飞来飞去的很好玩么？\n");
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("kee") < 1000 )
                return notify_fail("你的气不够！\n");
        if( me->is_ghost())
                return notify_fail("鬼魂无法使用召唤神雕！\n");         
 //       if( target )
 //               return notify_fail("召唤神雕只能对自己使用！\n");
        inv = all_inventory(me);
        carrying = 0;

        if ( sizeof(inv) ){
           map_array(inv, "drop_npc");
           if ( carrying )
             return notify_fail("不能背着其他生物召唤神雕！\n");
        }
        message_vision(HIG "\n$N运足内力长啸一声，一只雄健的神雕感受到$N的召唤，\n从翱翔的九天落到$N的身旁，静静的等候$N的命令！\n"NOR,me);
        message_vision(HIC"\n$N轻轻一纵，跃到神雕背上，拍了拍它的脖颈。\n" NOR, me);
        message_vision( HIG "\n神雕长啸一声，箭一般飞起，载着$N直入青云！\n\n"NOR,me);
        me->start_busy(5);
        call_out("move_yun", 3, me);
        return 1;
}

void drop_npc(object ob)
{
  if ( ob->is_character() )
    carrying = 1;
}
    
int move_yun(object me)
{
        me->interrupt_me(me,"death");
        tell_object(me,HIC"你翱翔于蓝天大地之间，名山大川尽收眼底，兴奋之余不由得一声长啸！\n"NOR);
        message_vision( HIW "\n神雕正在耐心地等待$N的命令！\n\n"NOR,me);   
        me->move ("/d/sky/yun");
        me->start_busy(5);
        input_to( (: call_other, __FILE__, "select_target", me :));
        return 1;
}

void select_target(object me, string name)
{
        object ob;


        if( !name || name=="" ) {
                write(HIG"神雕抖了抖翅膀，飞了回来。\n"NOR);
                return;
        }

        ob = find_player(name);
        if( !ob || !me->visible(ob) || wizardp(ob) )
                ob = find_living(name);
        if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob) || environment(ob)->query("no_fly")
                || environment(ob)->no_fly()) {
                write(HIY"神雕在苍空打了个盘旋，似乎找不到这么个人....\n"NOR);
                write(HIC"你要驾着神雕飞到那个人身边？"NOR);
                input_to( (: call_other, __FILE__, "select_target", me :));
                return;
        }
        if( me->is_fighting() ) {
                write("战斗中无法使用召唤神雕！\n");
                return;
        } else if( me->query("force") < 1000 ) {
                write("你的内力不够！\n");
                return;
        }
        if( ob->query("id") == "qiankun jiaotu" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }
        if( ob->query("id") == "killer" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }
        if( ob->query("id") == "xiao riben" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }
        if( ob->query("id") == "killer2" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }

        if( ob->query("id") == "ren zhi" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }

        if( ob->query("id") == "yuan shuai" ) {
                write(HIR"神雕异常不屑的看了你一眼，竟然猛地一个盘旋，把你丢在了半空！\n"NOR);
                return;
        }
        if( random(me->query("lea")) < 1 ) {
                write(HIR"神雕不屑的看了你一眼，远远地飞走了。\n"NOR);
                return;
        }
        if(  userp(ob) ) {
                write(HIR"神雕非常不屑的看了你一眼。\n"NOR);
                return;
        }
/*
        if( random(ob->query("max_force")) < (int)me->query("force") / 2 ) {
                write(HIY"神雕对你失望极了，一声长鸣，远远的飞走了！\n"NOR);
                return;
        }
*/


        me->add("force", -300);
        me->receive_damage("kee", 50);
  
        if( base_name(environment(ob))[0..8] == "/d/death/" || base_name(environment(me))[0..8] == "/d/death/")
        {
                write(HIY"神雕飞不到阴间去。\n"NOR);
                return;
        }
                        
        message_vision( HIG "\n神雕会心的看了你一眼，随即箭一般朝着目的地直飞而去！\n\n"NOR,me);
        me->move(environment(ob));
        me->start_busy(1);

        message_vision( HIY "\n一只神雕自远方飞来，$N跳下雕背，那只雕抖了抖翅膀，仍然盘桓在$N的上空。\n\n" NOR,me );
}




