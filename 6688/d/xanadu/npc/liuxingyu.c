#include <ansi.h>

inherit NPC;
inherit F_MASTER;
 
int auto_heal();
 
void create()
{
        seteuid(getuid());
        set_name("流星雨", ({"liuxing yu", "yu", "logs"}));
        set("title", HIC"天外飞仙"NOR);
        set("nickname", HIM"唯能极於情，"+HIG"故能极於剑"NOR);
        set("long", @TEXT
	他就是流星雨吗？就是那个年纪轻轻就身兼武当、茅山和大招寺之所长并
青出于蓝的绝代天骄吗？传说中的人物总是与光荣和骄傲相伴，可是面前的他随随
便便地站在那里，左手按剑，右手握着一只翡翠杯，嘴角露出一丝笑意，看起来就
象你身边最普通的一个朋友。
TEXT
        );
        set("gender","男性");
        set("age",22);

        set("con",50);
        set("str",50);
        set("spi",50);
        set("cor",50);
        set("cps",50);
        set("int",50);
        set("per",50);
        set("kar",50);
	
	set("max_kee",4000);
	set("max_gin",1000);
	set("max_sen",1000);
	set("max_force",3000);
	set("force",6000);
	set("force_factor",165);
	set("max_atman",1400);
	set("atman",2800);
	set("max_mana",1800);
	set("mana",3600);
	set("mana_factor",41);

	set_skill("taoism",200);
	set_skill("literate",201);
	set_skill("dodge",240);
	set_skill("parry",200);
	set_skill("throwing",101);
	set_skill("dugong",101);
	set_skill("buddhism",101);
	set_skill("music",51);
	set_skill("force",220);
	set_skill("qimen-bagua",71);
//        set_skill("iron-cloth",140);
	set_skill("sword",200);
	set_skill("move",100);
	set_skill("cuff",180);
	set_skill("spells",130);
	set_skill("magic",140);
	set_skill("unarmed",151);

        set_skill("taiji-shengong",240);
	set_skill("taiji-jian",200);
	set_skill("tiyunzong",220);
	set_skill("taiji-quan",200);
	set_skill("gouyee",130);
	set_skill("taosword",120);
	set_skill("necromancy",130);
	set_skill("qingcheng-steps",220);
//        set_skill("jin-gang",140);
	
	map_skill("force","taiji-shengong");
	map_skill("sword","taiji-jian");
        map_skill("parry","taiji-jian");
	map_skill("dodge","tiyunzong");
	map_skill("move","tiyunzong");
	map_skill("cuff","taiji-quan");
	map_skill("spells","necromancy");
//        map_skill("iron-cloth","jin-gang");

	prepare_skill("cuff","taiji-quan");

	create_family("纵横天骄门",1,"掌门");
        set("combat_exp",3000000);
        set("attitude","heroism");
        set("chat_chance",1);
        set("chat_msg", ({
		(: auto_heal :),
	}) );

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                  (: cast_spell, "feeblebolt" :),
                (: cast_spell, "invocation" :),
		(: auto_heal :),
        }) );
        
	setup();

        carry_object(__DIR__"obj/star")->wield();
        carry_object(__DIR__"obj/moon")->wield();
        carry_object(__DIR__"obj/belt")->wear();
        carry_object(__DIR__"obj/boots")->wear();

	add_money("gold",10);
}

int auto_heal()
{
	object me;

	me = this_object();
	
/*
	if( (int)(me->query("eff_kee")/me->query("max_kee")) < 60 )
	{
		command("halt");
		command("exert heal");
		command("exert heal");
		command("exert heal");
	}
*/

	if( (int)(me->query("kee")/me->query("eff_kee")) < 70 )
	{
		command("exert recover");
	}

	if( (int)(me->query("gin")/me->query("eff_gin")) < 70 )
	{
		command("exert regenerate");
	}
	if( (int)(me->query("sen")/me->query("eff_sen")) < 70 )
	{
		command("exert refresh");
	}
	return 0;
}
 


 
