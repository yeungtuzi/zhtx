/**************************************************************************/
// $Id: cuiyan-sword.c,v 1.1 2000/12/14 14:41:09 cmy Exp $
/**************************************************************************/

inherit SKILL;

mapping *action = ({

        ([      "action":               "$N使一招「远山眉黛横」，手中$w风似地向$n的$l刺去！",
                "damage":               80,
                "dodge":                70,
                "attack":               20,
                "damage_type":  "刺伤",
        ]),

        ([      "action":               "$N身形一转，一招「媚柳开青眼」$w如晨露闪烁，刺向$n的$l",
                "damage":               50,
                "force":                70,
                "attack":               30,
                "damage_type":  "刺伤",
        ]),

        ([      "action":               "$N手中$w一晃，一招「楼阁断霞明」迅捷无伦地劈向$n的$l",
                "damage":               80,
                "force":                90,
                "attack":               20,
                "damage_type":  "刺伤",
        ]),

        ([      "action":               "$N提气丹田，身型咋展，一招「帘幕春寒浅」直劈$n$l",
                "damage":               100,
                "force":                100,
                "attack":               10,
                "damage_type":  "刺伤",
        ]),

        ([      "action":               "$N移步侧身，使一招「花影和帘卷」剑光霍霍斩向$n的$l",
                "damage":               120,
                "force":                120,
                "attack":               5,
                "damage_type":  "刺伤",
        ]),

});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑，才能练剑法。\n");

        if( (int)me->query("kee") < 50 )
                return notify_fail("你的体力不够练这门剑法，还是先休息休息吧。\n");
        me->receive_damage("kee", 50);
        return 1;
}
int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出一招「杯延玉漏迟」，用手中的$v急削$N的五指。\n",
        "$n左脚踏前一步，一招「烛怕金刀剪」，手中的$v从侧面飘向$N之必救。\n",
        "$n手中的$v一抖，挽出一片剑花，一招「明月忽飞来」，撒向$N的全身。\n",
        "$n微退一步，手中的$v划出一条光弧，一招「花影和帘卷」，将$N的全身围住。\n",
});

string *unarmed_parry_msg = ({
"$n使出一招「远山眉黛横」，用手中的$v急砍$N。\n",
"$n左脚踏前踏，一招「媚柳开青眼」，手中的$v挥向$N之必救。\n",
"$n手中的$v一抖，一招「楼阁断霞明」，奔向$N。\n",
"$n手中的$v划出一招「帘幕春寒浅」，将$N的全身围住。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 40;
}
int practice_bonus()
{
        return 20;
}
int black_white_ness()
{
        return 30;
}


