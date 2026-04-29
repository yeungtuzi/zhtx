// undead.c

#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"後心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) );
}

void setup(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :) );
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

	if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
	if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
	if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;

	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 14 ) my["max_gin"] = 100;
		else if( my["age"] <= 20 ) my["max_gin"] = 100 + (my["age"] - 14) * my["str"];
		else if( my["age"] <= 30 ) my["max_gin"] = 100 + 7 * my["str"];
		else my["max_gin"] = 100 + 7 * my["str"] - (my["age"] - 30) * 10;
		if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
		if( my["max_gin"] < 0 ) my["max_gin"] = 1;
	}

	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 14 ) my["max_kee"] = 100;
		else if( my["age"] <= 20 ) my["max_kee"] = 100 + (my["age"] - 14) * my["con"];
		else if( my["age"] <= 30 ) my["max_kee"] = 100 + 7 * my["con"];
		else my["max_kee"] = 100 + 7 * my["con"] - (my["age"] - 30) * 8;
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
		if( my["max_kee"] < 0 ) my["max_kee"] = 1;
	}

	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 14 ) my["max_sen"] = 100;
		else if( my["age"] <= 20 ) my["max_sen"] = 100 + (my["age"] - 14) * my["spi"];
		else if( my["age"] <= 40 ) my["max_sen"] = 100 + 7 * my["spi"];
		else my["max_sen"] = 100 + 7 * my["spi"] - (my["age"] - 30) * 6;
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"] / 4;
		if( my["max_sen"] < 0 ) my["max_sen"] = 1;
	}

	if( !ob->query_temp("apply/armor") )
		ob->set_temp("apply/armor", 20);

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
