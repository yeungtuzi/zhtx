#include <ansi.h>

inherit "/std/char/doomnpc";

string do_poison();

void create()
{
	set_name("小话", ({ "xiao hua","emote"}) );
	set("long",@LONG
	小话本是唐门女弟子，深受门主太夫人欧阳敏的器重，甚至曾一度改姓唐
以便将来继承唐门衣钵。可是她并不安分，一帆风顺地学完了唐门的各种功夫之后，
弃师门于不顾，毅然和相公一起到了这里经营一座山庄。
LONG
	 );

	set("title",GRN"小小毒魔女"NOR);  
	set("nickname",MAG"醉过才知酒浓，"CYN"爱过方知情重"NOR);
	set("gender","女性");
	set("max_gin", 1000);
	set("max_kee", 4000);                    
	set("max_sen", 1000);
	set("max_force",4000); 
	set("max_mana",1000);
	set("mana",2000);
	set("max_atman",1000);
	set("atman",2000);
	set("force",8000);
	set("force_factor",150);     
	set("combat_exp",10000000);
	set("cor",100);
	set("cps",100);   
	set("spi",100);
	set("per",30);
	set("str",100);
	set("age",18);

	set_skill("sunv-xinfa", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("dugong",220);
	set_skill("force",200);
	set_skill("tiannv-sanhua",200);
	set_skill("throwing",200);
	set_skill("sword",200);
	set_skill("yuenv-jian",200);
	set_skill("tangmen-duzhang",200);
	set_skill("strike",200);
	set_skill("taxue-wuhen",200);
	set_skill("literate",230);

	map_skill("force","sunv-xinfa");
	map_skill("strike","tangmen-duzhang");
	map_skill("parry","tiannv-sanhua");
	map_skill("dodge","taxue-wuhen");
	map_skill("throwing","tiannv-sanhua");
	map_skill("sword","yuenv-jian");
      prepare_skill("strike","tangmen-duzhang");

	set_temp("apply/damage",250);
	set_temp("apply/attack",50);
	set_temp("apply/defense",50);
	set_temp("apply/armor",150);
	set_temp("apply/armor_vs_force",250);


	set("chat_chance",3);
      set("chat_msg", ({
		"小话咯咯地笑了几声，扮了个鬼脸。\n",
		"小话偷偷地看了你一眼，忽然低下了头，脸唰的一下红了起来。\n",
        }) );

	set("chat_chance_combat",90);
        set("chat_msg_combat", ({
		(: do_poison :),
        }) );

	setup();

	carry_object("/d/latemoon/obj/bamboo_sword")->wield();
	carry_object("/d/tangmen/obj/wuyingdu")->set_amount(100);
	add_money("thousand-cash",1);
        if(random(10)>2) carry_rnd_equip(2,4);
}                          

void init()
{
	object victim;
        set("shen",-1*this_player()->query("shen")/10);

	victim = this_player();
	//给没有中毒的开个小玩笑
	//
	//if( random(2) && !victim->query_condition("tm_poison") )
	if(0)
	{
		command("xixi");
		command("poison "+victim->query("id"));
	}
}
                             
int killed_enemy(object ob)
{
  command("kick "+ob->query("id"));
}                 
                     
int chat()
{
	object logs;                                         
	object *env;
	int i;

	//相濡以沫，啧啧...
	if( logs = present("liuxing yu",environment(this_object())) )
	{
		if( logs->query_condition("tm_poison") )
		{
			message_vision(GRN"\n$N向$n轻轻招了招手。\n"NOR,this_object(),logs);
			logs->command("halt");
			command("halt");
			command("exert unpoison liuxing yu");
		}
		//同仇敌忾 :P
		env = all_inventory(environment(this_object()));
		for(i=0;i<sizeof(env);i++)
			if( userp(env[i]) && (env[i])->is_fighting(logs) && !is_fighting(env[i]) )
			{
				command("heng "+(env[i])->query("id"));
				message_vision("$N生气地说，敢跟我家相公作对啊，哼！\n",this_object());
				kill_ob(env[i]);
			}
	}
	::chat();
}                       

string do_poison()
{
	object victim;

        if( !(victim=select_opponent()) ) return " ";
	
	if( random(13)==7 )
		message_vision(CYN"$N一剑刺出，不但去势凌厉之极，姿态更是优美异常，衣带随风飘舞，翩翩若天上仙子。\n"NOR,this_object());	                        
	if( random(13)==8 )
		message_vision(GRN"$N轻声一笑，手中竹剑兜转了回来，劲风带起了自己的如云长发。\n"NOR,this_object());

	if( victim->query_condition("tm_poison") > 40 )
	{
		command("exert quickpoison "+victim->query("id"));
	}                                             
	else
	{
		command("poison "+victim->query("id"));
	}
        return " ";

}
