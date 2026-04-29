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
	"demon",
	"celestial",
	"evil",
	});
string *name2=({
	"staff",
	"zhang",
	
});
string *name3=({
	"heaven",
	"iron",
	"ice",
	"dragon",
	"phoenix",
	"fire",
});
mapping etoc=([
	"heaven"	:	"玄天",
	"iron"		: 	"玄铁",
	"ice"		:	"寒冰",
	"fire"		:	"烈焰",
	"dragon"	:	"赤龙",
	"phoenix"	:	"天凤",
	"staff"		:	"杖",
	"zhang"		:	"杖",
	"demon"		:	RED"魔"NOR,
	"celestial"	:	WHT"仙"NOR,
	"evil"		:	BLK"邪"NOR,
	]);
	
varargs void init_staff(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | LONG );
	set("skill_type", "staff");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
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
