// punk.c 小流氓

inherit NPC;

void create()
{
	set_name("小流氓", ({ "punk", "xiao liumang", "liumang" }));
	set("gender", "男性");
	set("age", 15);
	set("long", "他是一个成天游手好闲的小流氓，长得倒是挺惹人喜欢的。\n");
	
	set("combat_exp", 100+random(400));
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 5+random(5));
	set_skill("dodge", 5+random(5));
	
	setup();
	add_money("coin",10);
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
	command("lovelook "+ob->query("id"));
}
	