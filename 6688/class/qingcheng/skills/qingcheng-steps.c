/* qingcheng-steps.c*/
inherit SKILL;

string *dodge_msg = ({
        "但是$n脚尖一点，身体向后一纵，避出三尺之外。\n",
        "$n意念一转,不退反进,倏地从$N头上跳过，避过了这一招。\n",
        "可是$n侧身一让，往旁跳出数尺,让$N这一招扑了个空。\n",
        "只见$n身影一晃,避实就虚,躲开这招。\n",
        
});

int valid_enable(string usage)
{
	if( !objectp(this_player()) )
		return (usage=="dodge");

        return ( (usage=="dodge") || ( this_player()->query("family/family_name")!="茅山派"?usage=="move":0 ) );
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的体力太差了，不能练习青城步法。\n");
        me->receive_damage("kee", 25);
        return 1;
}


