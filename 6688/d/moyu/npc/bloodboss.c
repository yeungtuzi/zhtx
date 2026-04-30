// master.c

#include <ansi.h>

inherit "/ldg/std/doomnpc";
inherit "/ldg/std/rnd_equipd";

int consider();

void create()
{
	set_name(RED "血影子" NOR, ({ "blood boss", "blood", "boss" }) );

	set("gender", "男性");
	set("age", 74);
	set("attitude", "aggressive");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 2000);
	set("max_atman", 2000);

	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 200);

	set("mana", 600);
	set("max_mana", 600);

	set("combat_exp", 3000000);
	set("score", 9000);
	set("max_kee",3000);

        set_skill("staff", 220);
	set_skill("unarmed", 220);
	set_skill("force", 300);
	set_skill("bolomiduo",200);
	set_skill("dodge", 220);
	set_skill("literate", 160);
	set_skill("parry", 220);
	set_skill("magic", 220);

	set_skill("cloudstaff", 220);
	set_skill("buddhism", 250);
	set_skill("essencemagic", 200);
	set_skill("notracesnow",200);
	
	map_skill("staff", "cloudstaff");
	map_skill("parry", "cloudstaff");
	map_skill("force", "bolomiduo");
	map_skill("magic", "essencemagic");
	map_skill("dodge", "notracesnow");
	map_skill("move",  "notracesnow");
	set_temp("apply/armor",300);
	
	set("chat_chance_combat", 80);  
        set("chat_msg_combat", ({
             (: consider :),
        }) );
        
	setup();

	carry_object(__DIR__"obj/staff")->wield();
	carry_object("/d/moyu/obj/nineflower");
	if(random(10)>3) carry_rnd_equip(2,4);
}

int consider()
{
	object me;
	// 2026-04-30: unused variable commented out
	// int fighting,hurt,force_fac;

	me = this_object();
	if( !environment(me) ) return 0;
	
	//消除自己的busy
	if( random(4) > 2 && is_busy() )
		interrupt_me(this_object(),"death");
	//自动疗伤
	if(query("eff_kee")<query("max_kee")*50/100&&query("guo")<3)
	{
	        add("guo",1);
	        set("eff_gin", (int)query("max_gin"));
	        set("gin", (int)query("max_gin"));
        	set("eff_kee", (int)query("max_kee"));
        	set("kee", (int)query("max_kee"));
        	set("eff_sen", (int)query("max_sen"));
        	set("sen", (int)query("max_sen"));       
        	set("max_force", (int)query("max_force"));
        	set("max_mana", (int)query("max_mana"));
        	set("max_atman", (int)query("max_atman"));
     		message_vision(HIG"$N"+HIG"吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴! \n"NOR,me);
	}
	
	//自动解毒
	if( query("auto_unpoison") && (query_condition("tm_poison") || query_condition("rose_poison") || query_condition("snake_poison")) )
	{
		command("halt");
		command("exert unpoison");
	}                            
	if(query("sen")<(query("eff_sen")*70/100))
		command("exert refresh");
	if(query("kee")<(query("eff_kee")*70/100))
		command("exert recover");
	if(query("gin")<(query("eff_gin")*70/100))
		command("exert regenerate");
	command("conjure shade sense");		
}