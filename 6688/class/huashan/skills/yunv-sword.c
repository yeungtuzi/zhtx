//众芳摇落独暄妍，占尽风情向小园。
//疏影横斜水清浅，暗香浮动月黄昏。
//霜禽欲下先偷眼，粉蝶如知合断魂。
//幸有微吟可相狎，不须檀板共金樽。

inherit SKILL;

mapping *action = ({
   ([   "action":
"$N使一招「众芳摇落独暄妍」，手中$w化为一道疾光刺向$n的$l",
     "damage":     20,
                "attack":          20,
     "force" :     50,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"只见$N半个急转，使出「占尽风情向小园」，一声娇喝中剑光冲天而起，扫向$n的$l",
     "damage":     30,
                "attack":          20,
     "force" :     60,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N淡淡一笑，一式「疏影横斜水清浅」舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
     "damage":     70,
                "attack":          20,
     "force" :     70,
     "damage_type":   "刺伤"
   ]),
  ([      "action":
"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式「暗香浮动月黄昏」",  
                "damage":           80,
                "attack":          20,
                "force" :           100,
                "damage_type":  "刺伤"
        ]),

   ([   "action":
"$N手中$w轻轻一抖，一式「霜禽欲下先偷眼」幻出一遍寒光罩向$n。\n$n只觉得浑身都被笼罩在$N的剑气之下",
     "damage":     50,
                "attack":          20,
     "force" :     100,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招「粉蝶如知合断魂」只看得$n眼花缭乱，哪里还能招架",
     "damage":     40,
                "attack":          20,
     "force" :     90,
     "damage_type":   "刺伤"
   ]),
   ([      "action":
"$N纤腰轻旋，使出一式「幸有微吟可相狎」，手中$w划出一道妙曼无方的弧线，直削向$n的$l",
                "damage":          70,
                "attack":          20,
                "force" :          120,
                "damage_type":  "割伤"
        ]),

   ([      "action":
"$N不闪不避，一式「不需檀板共金樽」，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "damage":          80,
                "attack":          20,
                "force" :          120,
                "damage_type":  "刺伤"
        ]),
   
});

int valid_learn(object me)
{
   object ob;
   if(me->query("gender")!="女性")
   return notify_fail("玉女十九式只能女子才能学。\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("你的内力不够，没有办法练玉女十九式。\n");

   if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
     return notify_fail("玉女十九式必须配合紫霞神功才能练。\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        if (random(me->query_skill("sword")) > random(180) && me->query("force") >random(150) && me->query("marks/ningsword") )
	{
                me->add("force", -10);
		return ([
		"action": "$N长剑使得兴发，突然间一声清啸，剑锋闪烁不定，\n围着$n身围疾刺，银光飞舞，猛地里\n一剑挺出，直刺$n$w，当真是捷如闪电，势若奔雷！！",
		"dodge":  -5,
		"parry":  -5,
		"attack": 30,
		"force":  180,
		"damage": 200,
		"undodgeable" : 12,
		"unparryable" : 15,		
		"damage_type": "刺伤"]);
	}
   return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30)
   return notify_fail("你的气不够，无法练玉女十九式。\n");   
   me->receive_damage("kee", 30);
   write("你按著所学练了一遍玉女十九式。\n");
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

mapping enable_req() {

	return( ([ 
		"dodge":"huashan-shenfa",
	        "force":"zixia-shengong",
		]) );

}

mapping level_req(int level) {

	return( ([
		"huashan-shenfa":5,	
	]) );
}

int query_faith_req(int skill) {
	return 2*skill+10;
}

int query_ally(string skill,int amount)
{
        if( skill=="junzi-sword" ) return 200;
        return 0;
}
