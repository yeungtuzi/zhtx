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
	"ghost",
	"celestial",
	});
string *name2=({
	"blade",
});
string *name3=({
	"heaven",
	"iron",
	"ice",
	"dragon",
	"phoenix",
	"pine",
	"song",
	"loveless",
	"fire",
});
mapping etoc=([
	"heaven"	:	"玄天",
	"iron"		: 	"玄铁",
	"ice"		:	"寒冰",
	"fire"		:	"烈焰",
	"dragon"	:	"天龙",
	"phoenix"	:	"飞凤",
	"pine"		:	"青松",
	"song"		:	"长歌",
	"loveless"	:	"忘情",
	"blade"		:	"刀",
	"divine"	:	HIY"神"NOR,
	"demon"		:	RED"魔"NOR,
	"ghost"		:	BLU"妖"NOR,
	"celestial"	:	WHT"仙"NOR,
	"evil"		:	BLK"邪"NOR,
	]);
	
varargs void init_blade(int damage, int flag)
{
	set("weapon_prop/damage", damage);
	set("flag", (int)flag | EDGED);
	set("skill_type", "blade");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "hack" }) );
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
