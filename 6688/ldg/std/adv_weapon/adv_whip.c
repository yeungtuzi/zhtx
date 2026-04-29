#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_EQUIP;

string *equip_color = ({
		BLK,
		RED,
		GRN,
		YEL,
		BLU,
		MAG,
		CYN,
		WHT,
	});  

mapping advanced_prop = ([
	"damage":20,
]);
string *name1=({
	"",
	"divine",
	"demon",
	"evil",
	});
string *name2=({
	"whip",
});
string *name3=({
	"heaven",
	"ice",
	"dragon",
	"phoenix",
	"fire",
});
mapping etoc=([
	"heaven"	:	"玄天",
	"ice"		:	"寒冰",
	"fire"		:	"烈焰",
	"dragon"	:	"天龙",
	"phoenix"	:	"飞凤",
	"whip"		:	"鞭",
	"divine"	:	HIY"神"NOR,
	"demon"		:	RED"魔"NOR,
	"evil"		:	BLK"邪"NOR,
	]);
	
varargs void init_whip(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "whip");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "whip" }) );
		}
}


varargs void random_generate(int level)
{
	adv_random_name(name1,name2,name3,equip_color,etoc,level);
	adv_random_prop(advanced_prop);
}

int reload_props(mixed props)
{
	return adv_reload_props(props,equip_color,etoc,advanced_prop);
}
