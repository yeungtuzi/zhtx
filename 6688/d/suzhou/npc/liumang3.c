// liumang3.c 流氓老大

inherit NPC;

void create()
{
	set_name("流氓老大", ({ "liumang tou", "tou","liumang" }));
	set("gender", "男性");
	set("age", 29);
	set("long", "他是一个成天游手好闲的流氓，一副威风的样子，好象是个老大。\n");
	
	set("combat_exp", 10000+random(10000));
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	add_money("gold",1);
	carry_object("/d/suzhou/npc/obj/lmcloth2")->wear();
}

void init()
{
	remove_call_out("greeting");
	call_out("greeting",1,this_player());
}

void greeting()
{   	
	object ob;
        ob=this_player();

        if( !ob || environment(ob) != environment() 
|| ob->query("gender")!="女性") return;
	command("say 花姑娘，过来陪大爷玩玩！！！！\n");
	command("loveshoe "+ob->query("id"));
}
	