// necromancy.c
#include <ansi.h>
inherit SKILL;

string *level_desc = ({
	BLU "新入道途" NOR,	
	HIB "初领妙道" NOR,
	HIB "略通道行" NOR,
	HIB "渐入佳境" NOR,
	HIR "道心稳固" NOR,
        HIR "呼风唤雨" NOR,
	CYN "一日千里" NOR,
	CYN "脱胎换骨" NOR,
	CYN "役鬼通神" NOR,
	CYN "霞举飞升" NOR,
	CYN "道满根归" NOR,
	HIG "移山倒海" NOR,
        HIG "妙造自然" NOR,
	HIC "不堕轮回" NOR,
	HIC "已证大道" NOR,
	HIW "天人合一" NOR,
});
string type() { return "knowledge"; }
string query_lev_desc(int lvl);
int valid_enable(string usage) { return usage=="spells"; }

int invalid_research()
{
	return 1;
}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism") < (int)me->query_skill("necromancy")/2 )
		return notify_fail("你的天师正道修为不够，无法领悟更高深的茅山道术。\n");
	return 1;
}

string cast_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

string scribe_spell_file(string spell)
{
	return CLASS_D("taoist") + "/necromancy/" + spell;
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"
			+ bug->name() + "吧！\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("你的法力不够。\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("你闭目凝神，神游物外，开始修习茅山道术中的法术....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
	}	
	else return 1;
return 1;
}

mapping enable_req() {

	return( ([ 
		"force":"gouyee",	
		"dodge":"qingcheng-steps",
		"parry":"taosword",
		"sword":"taosword",
		]) );

}

mapping level_req(int level) {

	return( ([
		"gouyee":20,
	]) );
}

int query_faith_req(int skill) {
	return 100+(skill+1)*skill/10;
}

string query_lev_desc(int lvl)
{
	int grade;
	grade = lvl / 10;
        if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

