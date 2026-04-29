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
	"armor":5,
]);
string *name1=({
	"golden",
	"iron",
	});
string *name2=({
	"hat",
	"cap",
	"helmet",
});
string *name3=({
	"",
});
mapping etoc=([
	"golden"	:	"金丝",
	"iron"		: 	"玄铁",
	"hat"		:	"帽",
	"cap"		:	"帽",
	"helmet"	:	"头盔",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_HEAD);
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
