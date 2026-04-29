// adv_armor.c

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
	"armor":15,
	"armor_vs_force":15,
	"armor_vs_spells":10,
]);
string *name1=({
	"golden",
	"dragon",
	"kings",
	"phoenix",
	});
string *name2=({
	"armor",
	"mail",
	"loricae",
});
string *name3=({
	"",
});
mapping etoc=([
	"golden"	:	"金丝",
	"armor"		:	"盔甲",
	"mail"		:	"链甲",
	"loricae"	:	"铠甲",
	"kings"		:	"帝王",
	"dragon"	:	"飞龙",
	"phoenix"	:	"飞凤",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_ARMOR);
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

