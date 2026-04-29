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
	"damage":5,
]);
string *name1=({
	"golden",
	"iron",
	});
string *name2=({
	"glove",
});
string *name3=({
	"",
});
mapping etoc=([
	"golden"	:	"金丝",
	"iron"		: 	"玄铁",
	"glove"		:	"手套",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_HANDS);
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
