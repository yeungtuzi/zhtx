// /obj/npc/robber.c
// 镖局用npc,劫匪
// NPC_DIR"robber"
// by mscat

#include <ansi.h>

inherit NPC;

mapping* skill_pack=({
([	"force_skill"	: "zixia-shengong",
	"unarmed_skill"	: "huashan-zhangfa",
	"weapon_type" 	: "sword",
	"weapon"	: "gangjian",
	"weapon_skill"	: "sword9",
	"dodge_skill"	: "huashan-shenfa"
]),
([	"force_skill"	: "taiji-shengong",
	"unarmed_skill"	: "taiji-quan",
	"weapon_type"   : "sword",
	"weapon"        : "gangjian",
	"weapon_skill"  : "taiji-jian",
	"dodge_skill"   : "tiyunzong",
]),
([	"force_skill"   : "mystforce",
	"weapon_type"   : "sword",
	"weapon"        : "gangjian",
	"weapon_skill"  : "mystsword",
	"dodge_skill"   : "mysterrier",
]),
([	"force_skill"   : "celestial",
	"unarmed_skill" : "celestrike",
	"weapon_type"   : "blade",
	"weapon"        : "gangdao",
	"weapon_skill"  : "spring-blade",
	"dodge_skill"   : "pyrobat-steps",
]),
([	"force_skill"   : "celestial",
	"unarmed_skill" : "celestrike",
	"weapon_type"   : "sword",
	"weapon"        : "gangjian",
	"weapon_skill"  : "six-chaos-sword",
	"dodge_skill"   : "pyrobat-steps",
]),
([	"force_skill"   : "fonxanforce",
	"unarmed_skill" : "liuh-ken",
	"weapon_type"   : "sword",
        "weapon"        : "gangjian",
	"weapon_skill"  : "fonxansword",
	"dodge_skill"   : "chaos-steps",
]),
([	"force_skill"   : "iceforce",
	"unarmed_skill" : "tenderzhi",
	"weapon_type"   : "whip",
	"weapon"        : "whip",
	"weapon_skill"  : "snowwhip",
	"dodge_skill"   : "stormdance",
	"female_only"	: 1,
])
});

void time_to_go();
void set_level(int level_number);
int do_rob(object victim);

void create()
{
	set_name("劫匪", ({ "robber", "jiefei", "fei"}));
	if (random(10)>3) set("gender", "男性" );
		else set("gender", "女性" );
	set("age", 16+random(33));
	set("long", "这是一个拦路抢劫行人货物的劫匪\n");
	setup();
	carry_object(OBJ_DIR"cloth")->wear();
}

void set_level(int level_number)
{
	int idx;
	idx=random(sizeof(skill_pack));
	if((int)skill_pack[idx]["female_only"]) 
		this_object()->set("gender", "女性" );
	set_skill("force",10*random(level_number)+10);
	set_skill(skill_pack[idx]["force_skill"],10*random(level_number)+10);
	set_skill("unarmed",10*random(level_number)+10);
	if(stringp(skill_pack[idx]["unarmed_skill"])) {
	set_skill(skill_pack[idx]["unarmed_skill"],10*random(level_number)+10);
	map_skill("unarmed",skill_pack[idx]["unarmed_skill"]);
	}
	set_skill(skill_pack[idx]["weapon_type"],10*random(level_number)+10);
	set_skill(skill_pack[idx]["weapon_skill"],10*random(level_number)+10);
	set_skill("dodge",10*random(level_number)+10);
	set_skill(skill_pack[idx]["dodge_skill"],10*random(level_number)+10);
	map_skill("force",skill_pack[idx]["force_skill"]);
	map_skill(skill_pack[idx]["weapon_type"],
		skill_pack[idx]["weapon_skill"]);
	map_skill("dodge",skill_pack[idx]["dodge_skill"]);
	set("combat_exp", 100*(800*random(level_number)+1));
	set("force", 10*(80*random(level_number)+1));
	set("max_force", 10*(80*random(level_number)+1));
	set("force_factor", 8*random(level_number)+8);
	::setup();
	carry_object(OBJ_DIR+"weapon/"+skill_pack[idx]["weapon"])->wield();
}

int do_rob(object victim)
{
	if(!objectp(victim)) {
		call_out("time_to_go", 2);
		return 1;
	}
	if (command("rob "+victim->query("id")))
		call_out("do_rob", 2, victim);
	remove_call_out("time_to_go");
	call_out("time_to_go", 20);
	return 1;
}

void time_to_go()
{
	command("say 风紧,扯呼!");
	destruct(this_object());
}
