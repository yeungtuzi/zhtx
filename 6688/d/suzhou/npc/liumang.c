// liumang.c 流氓

inherit NPC;

void create()
{
	set_name("流氓", ({ "liu mang", "liu" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的流氓，长得倒是白白胖胖的，也许以前有过钱。\n");
	
	set("combat_exp", 1000+random(4000));
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	add_money("silver",1);
	carry_object("/obj/cloth/cloth")->wear();
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
	command("kiss "+ob->query("id"));
}
	