// banruo.c 龙象般若功

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("banruo", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;

        if (((string)me->query("class") != "bonze") && i > 29)
                return notify_fail("你不是僧人，学不了高深的龙象般若功。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学龙象般若功。\n");

        if ( me->query("gender") == "无性" && i > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");

        if (i > 10 && (int)me->query("shen") > t * 100)
                return notify_fail("要学龙象般若功，你的表现还不够吧！ \n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

