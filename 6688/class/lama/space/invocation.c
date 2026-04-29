// /daemon/class/lama/space/invocation.c

inherit SSERVER;

int conjure(object me, object target)
{
        object soldier;

//        if( (string)me->query("gender")!="女性")
//                return notify_fail("这不是你能使用的神通!\n");
	if(!target) target=me;
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤护法神物！\n");
	if( !target->is_fighting() )
		return notify_fail(target->name()+"不需要护卫.\n");

        if( (int)me->query("atman") < 100 )
                return notify_fail("你的灵力不够了！\n");
        if( (int)me->query("sen") < 60 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);
        me->add("atman", -100);
        me->receive_damage("sen", 60);

        if( random(me->query("max_atman")) < 200  ||
                (me->query_skill("zang-buddhi",1)< 100)) {
                message("vision", "但是什麽也没有发生。\n", environment(me));
                return 1;
        }

        seteuid(getuid());
        if( random(5)<3 || (me->query_skill("space",1) < 150))
                soldier = new(NPC_DIR"vulture"); //护法灵鹫
        else
                soldier = new(NPC_DIR"wolfguard"); //雪山神狼

        soldier->move(environment(target));
	soldier->set_level(me->query_skill("space",1));
        soldier->invocation(target);
        me->start_busy(random(2));
        return 1;
}
