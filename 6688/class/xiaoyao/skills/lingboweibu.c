// lingboweibu.c 凌波微步

inherit SKILL;

string *dodge_msg = ({
	"$n一招「瞻忽在前」，轻轻巧巧地避了开去。\n",
	"却见$n一招「动若脱兔」，身形早已飘至三尺之外。\n",
	"但是$n一招「微尘不惊」，身形微动，$N始终差了半分。\n",
	"只见$n身形晃动，一招「若有若无」，$N扑了个空。\n",
	"$n姿势美妙，已经借一招「姑射仙人」退了开去。\n",
	"$n身子微侧，一招「静若处子」，轻轻闪过了$N的招式。\n",
	"可是$n使出一招「瞻忽在后」，身影已经绕到$N的后面！\n",
	"$N一招「若危若安」，身形飘忽不定，令$N无法捉摸。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	if( me->query("betrayer") )
		return notify_fail("师父决定不教你这项功夫。\n");
	if( (int)me->query_skill("qimen-bagua", 1) < 80 )
		return notify_fail("你的奇门八卦不够，无法领悟凌波微步。\n");
	if( (int)me->query_skill("literate", 1) < 80 )
		return notify_fail("你的文学素养不够，无法领悟凌波微步。\n");

	return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力太差了，不能练凌波微步。\n");
        me->receive_damage("kee", 30);
        return 1;
}

int effective_level()	{return 18;}

int query_faith_req(int skill) {return 100+skill*3;}
/*

mapping enable_req()
{
	return( ([
		"force" : "beiming-shengong",
	]));
}
*/

string perform_action_file(string action)
{
	return CLASS_D("xiaoyao") + "/lengboweibu/" + action;
}
