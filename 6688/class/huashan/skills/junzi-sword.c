// junzi-sword.c 君子剑
//writen by emote

/*只听得$N口中长吟：「良马既闻，丽服有晖，左揽繁弱，右接忘归。」，剑招配合了
诗句，挥舞得潇洒有致，连续两剑平平削出，先左后右，一气呵成。
$N口中又吟道：「风驰电逝，蹑景追飞。凌厉中原，顾盼生姿。」诗句是四字一句，
剑招也是四招一组，吟到「风驰电逝，蹑景追飞」时剑去奇速，於「凌厉中原，顾盼生
姿」这句上却是迅猛之馀，继以飘逸。
只听$N又吟道：「息徒兰圃，秣马华山。流□平皋，垂纶长川。目送归鸿，手挥五弦。」
这几句诗吟来淡然自得，剑法却是大开大阖，峻洁雄秀，尤其最後两句剑招极尽飘忽，
似东却西，绉上击下，一招两剑，难以分其虚实。  

$N口中慢慢吟哦：「俯仰自得，游心太玄，嘉彼钓叟，得鱼忘筌。」，先是从上直削而下
之後紧接手中$w从下划出一道圆弧，向上削去。
*/
inherit SKILL;

mapping *action = ({
([      "action" : "只听得$N口中长吟：「良马既闻，丽服有晖，左揽繁弱，右接忘归」，剑招配合了诗\n"+
"句，挥舞得潇洒有致，先是一招「左揽繁弱」，剑式无比凝重，接着又是一招「右接忘\n"+
"归」，剑招突然又变的无比潇洒，连续两剑平平削出，先左后右，一气呵成。\n",
        "force" : 40,
        "parry" : 5,
        "damage" : 20,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N口中又吟道：「风驰电逝，蹑景追飞。凌厉中原，顾盼生姿。」诗句是四字一句，\n"+
"剑招也是四招一组，吟到「风驰电逝，蹑景追飞」时剑去奇速，於「凌厉中原，顾盼生\n"+
"姿」这句上却是迅猛之馀，继以飘逸。\n",
        "force" : 50,
        "parry" : 7,
        "damage" : 20,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "只听$N又吟道：「息徒兰圃，秣马华山。流□平皋，垂纶长川」，这几句诗吟来淡然\n"+
"自得，剑法却是大开大阖，峻洁雄秀。\n",
        "force" : 80,
        "parry" : 10,
        "damage" : 50,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N口中曼声长歌：「目送归鸿，手挥五弦」，剑招极尽飘忽，似东却西，绉上击下，\n"+
"一招五剑，分刺向$n身上的头，颈，胸，腕，腿五个部位，难以分其虚实。\n",
        "force" : 120,
        "parry" : 20,
        "damage" : 70,
        "lvl" : 30,
        "damage_type" : "砍伤"
]),
([      "action" : "$N口中慢慢吟哦：「俯仰自得，游心太玄，嘉彼钓叟，得鱼忘筌。」，先是从上直\n"+
"削而下之後紧接手中$w从下划出一道圆弧，向上削去。\n",
        "force" : 140,
        "parry" : 20,
	"attack": 20,
        "damage" : 120,
        "lvl" : 100,
        "damage_type" : "刺伤"
]),
});



int valid_enable(string usage) { return (usage == "sword")|| (usage == "parry") ; }

int valid_learn(object me)
{
        if(me->query_skill("huashan-jianfa",1)<100)
          return notify_fail("你连扎根基的功夫都没学好，还想学「君子剑」？\n");
       if ((int)me->query("max_force") < 800)
                return notify_fail("你的内力不够。\n");
        return 1;
}
string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("junzi-sword", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                          return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;
        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        if ((int)me->query("max_force")<800)
        return notify_fail("你的内力太弱了，强练「君子剑」伤身体的。\n");
        if((int)me->query("kee")<40)
        return notify_fail("你的体力太弱了，还是休息一下再练吧。\n");
        me->receive_damage("kee",25);
        return 1;
}
int query_ally(string skill,int amount)
{
        if( skill=="yunv-sword" ) return 200;
        return 0;
}
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
        return 20;
}


mapping enable_req() {

	return( ([ 
		"dodge":"huashan-shenfa",
		"force":"zixia-shengong",
	]) );

}

mapping level_req(int level) {

	return( ([
		"huashan-jianfa":100,	
	]) );
}

int query_faith_req(int skill) {
	return 6*skill+1;
}
