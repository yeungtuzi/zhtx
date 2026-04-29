#include <ansi.h>

inherit "/std/char/doomnpc";

int remove_effect(object ob);

void create()
{
	object sword;

	set_name("辛十三娘", ({ "lady xin","lady","xin"}) );
	set("long",
		"辛十三娘是江湖上臭名昭著的女魔头，好杀成性。\n"
		"她擅长发剧毒暗器，更加不可思议的本领是她有护体色的本领。\n"
		"可以随时销声匿迹，然后突然出现。\n"
		"三年前她在湘北碰上恶名更盛的女魔头艳无忧后就再没有人见过她。\n"
	 );

	set("title",RED"十步杀一人，千里不留行"NOR);
	set("gender","女性");
	set("age",38);

	set("max_gin", 2000);
	set("max_kee", 4000);                    
	set("max_sen", 2000);
	set("max_force",4000); 
	set("force",10000);
	set("force_factor",200);     
	set("combat_exp",3000000);
	set("bellicosity",500000);
	set("cor",100);      
	set("int",100);

	set_skill("tiannv-sanhua", 220);
	set_skill("dodge", 200);
	set_skill("mysterrier",200);
	set_skill("parry", 200);
	set_skill("throwing",220);
	set_skill("force",800); //防止别人来弹指
	set_skill("sunv-xinfa",200);
	set_skill("dugong",220);

	map_skill("throwing","tiannv-sanhua");
	map_skill("parry","tiannv-sanhua");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");
	map_skill("force","sunv-xinfa");

	set_temp("apply/attack",100);
	set_temp("apply/dodge",100);

	set("chat_chance",20);
        set("chat_msg", ({
		(: random_move :),
        }) );

	set("shen",1);
	set("score",1);

	setup();

	carry_object(__DIR__"obj/duzhen")->wield();
	carry_object("/d/tangmen/obj/wuyingdu");
}

int chat()
{
	object victim;
	
	victim = this_player();

	switch(random(10))
	{
		case 0:
		case 1:
		case 2:
		case 3:                                        
		case 4:
		case 5:
			command("poison "+victim->query("id"));
			break;
		case 6:
		case 7:
			if( victim->query_condition("tm_poison") > 10 && is_killing(victim) )
			{
				command("grin "+victim->query("id"));
				kill_ob(victim);
				command("exert quickpoison "+victim->query("id"));
			}
			break;
		case 8:
		case 9:
			if( query("env/invisibility") || !is_fighting() ) break;
			message_vision(BLK"你眼前一花，已经不见了$N的踪影。\n"NOR,this_object());
			set("env/invisibility",1);
			call_out("remove_effect",60,this_object());			
			break;
	}
	return	::chat();                                                
}                              

int remove_effect(object me)
{
	remove_call_out("remove_effect");
	message_vision(BLU"$N的身形突然又显露了出来，让所有的人大吃一惊。"NOR,me);
	me->delete("env/invisibility");
	me->start_busy(3);
	return 1;
}