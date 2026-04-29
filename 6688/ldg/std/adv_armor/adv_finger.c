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
	"armor_vs_spells":3,
	"add_max_kee":5,
	"add_max_sen":3,
	"add_max_gin":3,
]);
string *name1=({
	"",
	"golden",
	"jade",
	"agate",
	"diamond"
	});
string *name2=({
	"ring",
	"finger",
});
string *name3=({
	"",
	"fire",
	"wind",
	"ice",
});
mapping etoc=([
	"golden"	:	"黄金",
	"jade"		:	"碧玉",
	"agate"		:	"玛瑙",
	"diamond"	:	"宝石",
	"ring"		:	"戒指",
	"finger"	:	"指环",
	"fire"		:	"烈焰",
	"wind"		:	"定风",
	"ice"		:	"寒冰",
	]);
	
void setup()
{
	//if( clonep(this_object()) ) return;
	set("armor_type", TYPE_FINGER);
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
