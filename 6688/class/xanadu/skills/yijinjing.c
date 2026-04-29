// 易筋经
// force/strike/parry/dodge/iron-cloth
// yijinjing.c
// by masterall

#include <ansi.h>


inherit FORCE;

mapping *action = ({
([      
        "action" : HIW"$N一掌轻轻拍落，波的一声响，正好击向$n脑门正中的“百会穴”上，\n$n一格一退，竟没半点效用。"NOR,
        "force" : 1500,
        "dodge" : 100,
        "attack": 100,
        "parry" : 100,
        "damage": 1500,
        "undodgeable": 100,
        "unparryable": 100,
        "damage_type" : "瘀伤"
]),
([      "action": HIW"$N提起手掌，往$n头部拍将下去，$n急忙接架相迎，\n不料$N突然大喝一声，右掌改向$n左肩击去，$n待要变招，\n谁知右掌这一招中途变向，纯真虚招，意随圈转，波的一声轻响，已击向$n的顶门！"NOR,
        "attack":               100,
        "damage":               2000,
        "dodge":                100,
        "parry":                100,
        "force":                2000,
        "undodgeable":          100,
        "unparryable":          100,
        "damage_type":  "瘀伤"
]),                                
});

string *parry_msg = ({
        "$n全不闻不见，全不理睬，$N攻到$n身前两尺之处，突然间又如撞上了一堵无形气墙，\n更似撞进了一张渔网之中，攻势虽猛，却是无可施力。\n",
});

string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int counter_attack_ratio()
{
        return 100;
}                 

int attack_ratio()
{       
        return 200;
}

int query_relieve_coff() {
        return 90;
}

string query_relieve_message() {
        return HIW"$n双手合什，说道：“阿弥陀佛，佛门善地，施主不可妄动无明。”\n$n双掌只这么一合，便似有一股力道化成一堵无形高墙挡在$N和$n之间\n$N排山倒海的攻势撞在这堵墙上，登时无影无踪，消于无形。\n"NOR;
}


string *dodge_msg = ({
        "$n在$N攻势推送之下，便如纸鸢般向前飘出数丈，身子轻飘飘地，浑不似血肉之躯！\n",
});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_enable(string usage) { return (usage == "force"  || usage == "sword" || usage == "parry" || usage == "dodge"|| usage == "strike"); }

int valid_learn(object me)
// need more limit here
{
        return notify_fail("易筋经不能学。\n");
}

int practice_skill(object me)
{
        return notify_fail("易筋经不能练。\n");
}

string exert_function_file(string func)
{
        return __DIR__"yijinjing/" + func;

}


string query_force_type() {

        return "佛家内功";
}

                                            
int npc_only() {

        return 1;
}

