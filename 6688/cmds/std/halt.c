// halt.c

#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *enemys;
        int i;
        
        if( !me->is_fighting() ) {
                if( me->is_busy() ) {
                        me->interrupt_me(me, "halt");
                        write("Ok.\n");
                        return 1;
                }
                else
                return notify_fail("你现在并没有在战斗。\n");
        }

        if( wizardp(me) ) {
                me->remove_all_killer();
                message_vision("$N用巫师的神力停止了这场打斗。\n", me);
                return 1;
        }
        if( me->query_temp("pk_id") ) {
                string *pk_id;
                object ob;
                pk_id=me->query_temp("pk_id");
                for(i=0;i<sizeof(pk_id);i++) {
                        if( ob = find_living(pk_id[i]) && me->is_killing(ob) ) {
                                return notify_fail(RED"你正在和人性命相搏,不能停手罢斗.\n"NOR);
                        }
                }
        }

        if(!me->is_busy()) {
                //不应该是remove_all_enemy,应该只是自己停止出手,并和不杀自己的人解除战斗状态.
                // me->remove_all_enemy();
                me->clean_up_enemy();
                enemys = me->query_enemy();
                i = sizeof(enemys);
                while( i-- )
                {
                        if( !enemys[i]->is_killing(me) || !living(enemys[i]) )
                                me->remove_enemy(enemys[i]);
                }
                message_vision("$N向後一跃，离开战圈罢手不斗了。\n", me);
        } else return notify_fail("你正忙着呢！\n");

        write("Ok.\n");
        return 1;
}

int help(object me)
{
   write(@HELP
指令格式: halt

可以停止所有与你(□)正在进行的比试，但是正在跟你性命相搏的敌人通常
不会轻易言和。
HELP
   );
   return 1;
}


