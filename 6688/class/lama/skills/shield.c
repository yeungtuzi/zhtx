// /daemon/skill/shield.c
// 佛门护体神功
// by mscat

inherit SKILL;

string *absorb_msg = ({
        "$n双手合十,低吟一声佛号,全身泛起金色的光辉"
});

mapping *action = ({
        ([
        "action":"$N双手合十,低吟一声佛号,全身泛起金色的光辉",
        "force":100,
        "damage_type":  "内伤"
        ])
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int valid_learn(object me)
{
        if( me->query_skill("zang-buddhi", 1) <
                me->query_skill("shield", 1))
        return notify_fail("你的藏传佛法太差了,无法继续领悟护体神功.\n");
        if( me->query_skill("bolomiduo", 1) <
                me->query_skill("shield", 1))
        return notify_fail("你的波萝蜜多心经太差了,无法继续领悟护体神功.\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail("护体神功不能练习.\n");
}

string perform_action_file(string action)
{
        return CLASS_D("lama") + "/shield/" + action;
}

int effective_level() { return 10;}

int learn_bonus()
{
        return 10;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 80;
}

string *parry_msg = ({
        "$n双手合十,低吟一声佛号,全身泛起金色的光辉,挡住了$N手中的$w"
});

string *unarmed_parry_msg = ({
        "$n双手合十,低吟一声佛号,全身泛起金色的光辉,挡住了$N的攻势。\n"
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

