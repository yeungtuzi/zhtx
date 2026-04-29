
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int point,avf;

        if( !arg ) return notify_fail("请用help transfer来看看怎么用。\n");

        if( me->is_busy() || me->is_fighting() ) return notify_fail("你现在没有空！\n");
        if(sscanf(arg, "exp with %d", point)==1 )
        {
                if(point <= 0) return notify_fail("想作弊? hehe\n");

                if( ((int)me->query("potential")-(int)me->query("learned_points")) < point  )
                        return notify_fail("你没有那么多的潜能。\n");

                me->add("learned_points",point);
                me->add("combat_exp",point);
                printf("ok\n");
                return 1;
        }
        if( arg=="avf" )
        {
                if(me->query("wlshw") < 3) return notify_fail("你的武林声望不够用来提高自身的防御力！\n");

                if( (int)me->query("armor_vs_force") > 999  )
                        return notify_fail("你的Armor_vs_force已经达到上限了，无法继续提升了。\n");

                me->add("armor_vs_force",1);
                me->add("wlshw",-3);
                avf = me->query("armor_vs_force");
                printf(HIC"你的防御指数"+HIW"Armor_vs_force"+HIC"已经提高到了"+HIY"："+chinese_number(avf)+"点"+HIC"！\n"NOR);
                return 1;
        }
        if( arg=="betrayer" )
        {
                if(me->query("wlshw") < 200) return notify_fail("你没有那么多的武林声望。\n"); 
                if(me->query("betrayer") < 1) return notify_fail("你没有判过师吧。\n");
                me->add("wlshw",-200);
                me->add("betrayer",-1);
                printf("ok\n");
                return 1;
        }
        if( arg == "age")
        {
                if ( me->query("mud_age") < 2*86400 ) return notify_fail("你已经够年轻了，还想降啊!!!\n");
                if(me->query("wlshw") < 10) return notify_fail("你没有那么多武林声望。\n");
                me->add("wlshw",-10);
                me->add("mud_age",-68400-random(40000));
                if( me->query("mud_age") == 0) me->set("mud_age",0);
                printf("你看起来年轻了不少。\n");
                return 1;
        }
        if( arg=="research" )
        {
                if(me->query("wlshw") < 300) return notify_fail("你没有那么多的武林声望。\n"); 
                if(me->query("can_research")) return notify_fail("你已经可以research了。\n");
                me->add("wlshw",-300);
                me->set("can_research",1);
                printf("ok\n");
                return 1;
        }
        return 0;
}
int help(object me)
{
  write(@HELP
转换指令使用方法:

transfer exp with <潜能点>- 用潜能转换为经验。
transfer betrayer         - 用一定的武林声望为代价，来降低判师次数。
transfer age              - 用一定的武林声望为代价，使自己更年轻。
transfer avf              - 用一定的武林声望为代价，提高自己的防御力Armor_vs_force。

HELP
    );
    return 1;
}

