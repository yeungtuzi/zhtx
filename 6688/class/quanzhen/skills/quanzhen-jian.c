//quanzhen-jian.c      全真剑法
inherit SKILL;

mapping	* action=({
    ([	"action":"$N一招「孤山霁雪」，手中$w剑意凛然，一股慷慨悲壮之势随着
                 剑身前指而弥散开来，迅疾无比的刺向$n眉心",
        "force" :170,          
        "parry" :5,
        "dodge" :15,
        "damage":25,
        "lvl" : 0,
        "zhaoshi" : "「孤山霁雪」",
        "damage_type":"刺伤"   ]),
    ([  "action":"不待$n变招，$N紧接着又一招「葛岭朝歌」，手中$w如搜魂之剑，
                  如影随形的朝$n身上刺来",
        "force" :80,        
        "parry" :10,
        "dodge" :15,
        "damage":130,
        "lvl"   :50,
        "zhaoshi" : "「葛岭朝歌」",
        "damage_type":"刺伤"    ]),
    ([  "action":"只见剑光一闪，$N使出一招「江天暮雪」，空气中只见一道淡淡的
                 剑气闪过，转眼之间$n只觉眼前剑光闪动，剑气慑人",
        "force" :90,
        "parry" :5,
        "dodge" :15,
        "damage":140,
        "lvl"   :55,
        "zhaoshi" : "「江天暮雪」",
        "damage_type":"刺伤" ]),
    ([  "action":"$N使出一招「两峰白云」，身随剑走，在空中身形一转，手中$w
                 绽出了无数剑花，刺向$n的各处穴道",
        "force" :120,
        "parry" :5,
	"attack":5,
        "dodge" :20,
        "damage":160,
        "lvl"   :70,
        "zhaoshi" : "「两峰白云」",
        "damage_type":"刺伤"    ]),
    ([  "action": "$N反手一挥，一招「曲院风荷」，剑尖斜指，手中$w从一个意想
                  不道的方向直刺$n的咽喉。",
        "force" :150,
        "parry" :10,
	"attack":15,
        "dodge" :25,
        "damage":190,
        "lvl"   :94,
        "zhaoshi" : "「曲院风荷」",
        "damage_type" : "刺伤"  ]),    
});

string *parry_msg = ({
    "$n身体一个平移，使出一招「平沙落雁」，手中的$v化作一天剑雨，将$N的攻势
     湮灭在其中。\n",
    "$n剑锋一侧，使出一招「平湖秋月」，手中的$v舞得密不透雨，只听见一阵迅疾
     的兵器接触之声，磕开了$N的$w。\n",
    "$n将手中的$v一抖，一招「六桥烟柳」，化作点点青光，$N顿觉无从下手，无奈
     只得收招自保。\n",
    "$n反手一招「烟寺晚钟」，剑锋斜指，划出一道长虹，手中$v一下就荡开了$N的
     $w。\n",
});

int valid_learn(object me)
{
    if ( (int)me->query_skill("dodge",1) < 40 )
        return notify_fail("你的身法不够，没有办法练全真剑法。\n");
    if ( (int)me->query("force") < 200 )
        return notify_fail("你的内力不够。\n");    

    if ( (int)me->query_skill("xiantian-gong", 1) < 20 )
        return notify_fail("你的先天功火候太浅。\n");
               
    return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int practice_skill( object me )
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够练全真剑法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

int valid_enable(string usage) { return (usage == "sword")||(usage == "parry"); }


mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("quanzhen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

string query_parry_msg(object weapon)
{   
	if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
}

string  perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}
mapping enable_req() {

	return( ([ 
		"force":"xiantian-gong",	
	]) );

}

mapping level_req(int level) {

	return( ([
		"xiantian-gong":20,	
	]) );
}

int query_faith_req(int skill) {
	return 10;
}

int query_ally(string skill,int amount)
{
	if( skill=="yunu-jianfa" ) return 150;
	return 0;
}
