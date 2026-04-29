// liumang2.c 女流氓

inherit NPC;

void create()
{
	set_name("女流氓", ({ "female punk", "punk", "liumang" }));
	set("gender", "女性");
	set("age", 20);
	set("long", "一个流里流气的女人，穿得很风骚。\n");
	
	set("combat_exp", 5000+random(5000));
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 40+random(10));
	set_skill("dodge", 50+random(10));
	
	setup();
	add_money("silver",5);
	carry_object("/d/suzhou/npc/obj/lmcloth")->wear();
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
|| ob->query("gender")!="男性" || random(100)<=60 ) return;
	command("lovelook "+ob->query("id"));
}
	