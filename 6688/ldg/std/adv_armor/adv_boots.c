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
]);
string *name1=({
	"fire",
	"wind",
	"ice",
	});
string *name2=({
	"boots",
	"shoes",
});
string *name3=({
	"",
	"ghost",
});
mapping etoc=([
	"fire"		:	"烈火",
	"ice"		:	"玄冰",
	"wind"		:	"神风",
	"boots"		:	"靴",
	"shoes"		:	"鞋",
	"ghost"		:	"魅影",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;

	set("armor_type", TYPE_BOOTS);
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
