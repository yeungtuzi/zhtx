
inherit NPC;

void create()
{
	set_name("当值太监", ({ "dangzhi taijian", "taijian"}));
	set("gender", "无性");
	set("age", 15+random(60));

	set("combat_exp", 50000);
	set("shen_type", 0);

	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	add_money("silver", random(10));
	carry_object(__DIR__"obj/tj-cloth")->wear();
}
	
int accept_object(object who,string ob)
{	if(ob="pi tiao")
	{ who->add("marks/got",-1);
	 message_vision("当值太监看了看批条，说道：“嗯，你可以走了。”\n",who);
	 return 1;
	}
	else return 0;
}
void init()
{
	add_action("drop","drop");
	add_action("give","pray");
}
int drop(object who,string arg)
{	if(arg=="ruantia" ||arg=="tongxian"||arg=="sichou")
	  who->add("marks/got",-1);
	return 1;
}
