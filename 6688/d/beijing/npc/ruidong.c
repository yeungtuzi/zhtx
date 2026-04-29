// ruidong.c
//writen by pock
#include <ansi.h>
inherit NPC;
void greeting(object who,int stage);
string *greeting_msg = ({

	});
void create()
{       
	set_name("瑞栋", ({ "rui dong","rui","dong" }) );
	set("gender", "男性" );
	set("age", 43);
	set("title",HIC"副总管"NOR);
	set("long", @TEXT
御前侍卫副总管，武功了得，仅次于御前侍卫总管多隆，在侍卫队中一位极为
了不起的人物。
TEXT
	);
	set("combat_exp", 1800000);

	set("str", 30);
	set("con", 30);
	set("int", 27);
	set("max_force",2000);
	set("force",4000);
	set("shen_type", -1);

	set("attitude", "aggressive");
	set_skill("dodge", 150);
	set_skill("cuff",180);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("liuh-ken",150);
	map_skill("cuff","liuh-ken");
	prepare_skill("cuff","liuh-ken");
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 40);
	set("force_factor",100);
	set("marks/happened",0);
	setup();
	add_money("gold", random(3));
	carry_object(__DIR__"obj/junfu")->wear();
	carry_object("/d/beijing/obj/book14_5");
}


void die()
{
	int i;
	object killer;

	if(objectp(killer = query_temp("last_damage_from")))
	    killer->set("marks/killruidong", 1);

	::die();

}
