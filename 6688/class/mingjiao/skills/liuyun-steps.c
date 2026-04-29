// taxue-wuhen
// yuer

inherit SKILL;

string *dodge_msg = ({
        "$n真气荡漾，清啸连连，身形借机滑出丈外。\n",
        "$n双脚轻踏九曲，身形无比美妙地荡开数尺。\n",
        "$n腾空一跃，双脚凌空虚踏，陡然拔高丈许，$N招数尽数落空。\n",
        "$n身形晃动，全身化作无数虚影掠出丈外。\n",
        "$n猛吸一口气，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力太差了，不能练流云步法。\n");
        me->receive_damage("kee", 30);
        return 1;
}

int query_faith_req(int skill) {
	return 10;

}



