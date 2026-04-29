#include <ansi.h>
#include "/ldg/std/adv_armor.h"

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
	"armor":10,
	"armor_vs_force":4,
	"armor_vs_spells":4,
]);
string *name1=({
	"golden",
	"iron",
	"ice",
	"dragon",
	"tiger",
	"phoenix",
	});
string *name2=({
	"vest",
	"cloth",
	"wraistcoat",
});
string *name3=({
	"",
	"heaven",
	"star",
	"moon",
	"sun",
});
mapping etoc=([
	"golden"	:	"金丝",
	"iron"		: 	"玄铁",
	"ice"		:	"玄冰",
	"dragon"	:	"青龙",
	"tiger"		:	"白虎",
	"phoenix"	:	"朱雀",
	"vest"		:	"背心",
	"cloth"		:	"战袍",
	"wraistcoat"	:	"甲",
	"heaven"	:	"九天",
	"star"		:	"晨星",
	"moon"		:	"明月",
	"sun"		:	"烈日",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_CLOTH);
	set("armor_prop/armor", 1);
	::setup();
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
