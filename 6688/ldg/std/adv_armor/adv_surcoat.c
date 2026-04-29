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
	"armor":3,
	"armor_vs_force":1,
	"armor_vs_spells":1,
]);
string *name1=({
	"golden",
	"ice"
	});
string *name2=({
	"cloak",
	"surcoat",
	"mantle",
});
string *name3=({
	"",
});
mapping etoc=([
	"golden"	:	"金丝",
	"ice"		:	"玄冰",
	"cloak"		:	"披风",
	"mantle"	:	"斗篷",
	"surcoat"	:	"披风",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_SURCOAT);
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
