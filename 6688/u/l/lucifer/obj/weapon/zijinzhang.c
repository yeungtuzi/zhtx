//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 紫金杖

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit STAFF;

//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIR "紫金杖" NOR , ({ "zijin zhang", "zhang" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一把用紫金精心打造的禅杖，紫光中透着寒气，令人不寒而栗\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "violet-gold");
                set("wield_msg", HIM "一道紫光闪过之后，$N手里多了把称心如意的$n" HIM + "。\n天地间刹时黯然失色，$N只觉得全身充满了力量。\n" NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
                set("weapon_prop/attack", this_player()->query_skill("cloudstaff",1)/7);   
                set("weapon_prop/armor", this_player()->query_skill("zang-buddhi",1)*2);         
        }
    init_staff(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("cloudstaff",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

void init()
{
        add_action("do_zhaohuan","zhaohuan");     
}

int do_zhaohuan()
{
        object soldier;
        object me,target;
        me=this_player();


        if(!target) target=me;

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤护法神物！\n");

        if( !target->is_fighting() )
                return notify_fail(target->name()+"不需要护卫.\n");

        if( (int)me->query("atman") < 1000 )
                return notify_fail("你的灵力不够了！\n");
        if( (int)me->query("sen") < 60 )
                return notify_fail("你的精神无法集中！\n");

        message_vision(HIC"$N手舞紫金杖，喃喃地念了几句咒语。\n", me);
        me->add("atman", -500);
        me->receive_damage("sen", 60);

        if( random(me->query("max_atman")) < 200  ||
                (me->query_skill("cloudstaff",1)< 200)) {
                message("vision", "但是什麽也没有发生。\n", environment(me));
                return 1;
        }

        seteuid(getuid());
        if( random(5)<3 || (me->query_skill("cloudstaff",1) < 300))
                soldier = new("obj/npc/vulture"); //护法灵鹫
        else
                soldier = new("obj/npc/wolfguard"); //雪山神狼

        soldier->move(environment(target));
        soldier->set_level(me->query_skill("cloudstaff",1));
        soldier->invocation(target);
        return 1;
}



