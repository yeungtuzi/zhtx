// destroy.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        int max;
        object obj=present("killer",environment(me));
        if ( !obj||!(me == obj->query("owner")))
        return notify_fail("什麽？\n");
        if(!arg) return notify_fail("你要废谁的武功？\n");
        ob = present(arg, environment(me));
        if (!ob)   return notify_fail("你要废谁？\n");
        if (me->query("cttask/var") != "废武"  || ob->query("var") != "废武") return 0;

        if (me->is_busy()) return notify_fail("你正忙着呢。\n");

        if ( living(ob) )   return notify_fail("想废"+ob->name()+"的武功必须先把他打昏。\n");

        message_vision(HIR"$N运内力于食指，连点$n十八处大穴。\n"NOR,me,ob);

        if (random(2)==1)
        {
                message_vision(GRN"\n$N醒来后挣扎了几声，黯然的离开了。\n"NOR,ob);
                me->set("cttask/end_time",time());
                me->delete("cttask/get");
                me->set("cttask/done",1);
                destruct(ob);
                return 1;
        }
        else
        {
                me->start_busy(1);
                ob->revive();
                message_vision(HIC"\n$N不知从哪里来的力气，“噌”的一声跳了起来，奋起反抗。\n"NOR,ob);
                max = ob->query("max_gin");
                ob->set("eff_gin",max);
                ob->set("gin",max);
                max = ob->query("max_kee");
                ob->set("eff_kee",max);
                ob->set("kee",max);

                max = ob->query("max_force");
                ob->set("force",max);
                max = ob->max_food_capacity();
                ob->set("food",max);
                max = ob->max_water_capacity();
                ob->set("water",max);
                return 1;
        }

}

int help(object me)
{
        write(@HELP
指令格式 : destroy <人物>

此指令用来费人武功

HELP
    );
    return 1;
}


