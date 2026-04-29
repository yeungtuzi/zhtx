// azi.c 阿紫

inherit NPC;
void consider();
inherit F_MASTER;

void create()
{
	set_name("阿紫", ({ "a zi", "azi" }));
	set("title", "星宿派小师妹");
	set("long", @LONG
阿紫是星宿老怪丁春秋收留的孤儿，在星宿派虽然只是小师妹，
但是很得丁春秋的喜欢。她容颜俏丽，可是一双眼睛总是透着邪
气。这时候她不知道又在想什么坏主意。
LONG);
	set("gender", "女性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("per", 29);    
	set("elo", 200);
	
	set("max_kee", 600);
	set("max_gin", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 20);

	set("combat_exp", 200000);
	set("score", 30000);

	set("wimpy", 50);

	set("inquiry", ([
		"神木王鼎" : "神木王鼎在丁春秋那里，不过不知他藏在哪里？\n",
		"丁春秋" : "连星宿老怪的名字都没听说过，你真笨！\n",
	]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );

	set_skill("force", 80);
	set_skill("huagong-dafa", 70);
	set_skill("dodge", 40);
	set_skill("move", 60);
	set_skill("strike", 70);
	set_skill("xingxiu-duzhang", 40);
	set_skill("parry", 60);
	set_skill("literate", 50);
	set_skill("dugong", 50);
	set_skill("fushi-dugong", 50);
	set_skill("flattering", 200);
	
	map_skill("force", "huagong-dafa");
	map_skill("strike", "xingxiu-duzhang");
  	map_skill("parry", "xingxiu-duzhang");
	map_skill("dugong", "fushi-dugong");

	prepare_skill("strike", "xingxiu-duzhang");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object(__DIR__"obj/purple_cloth")->wear();
	add_money("gold", random(3));
}

void attempt_apprentice(object ob)
{
	command("say 要拜我为师，先给我磕上九个响头(kneel)。");
	add_action("do_kneel", "kneel");
	command("xixi");                                       
	ob->set_temp("apprentice_azi",1);
}

int do_kneel(string arg)
{
	object ob;

	ob = this_player();
	
	message_vision("$N跪在地上，“咚咚咚”如捣蒜般向阿紫连磕了九个头！\n", ob);
	ob->receive_damage("kee", 20);
	if( !ob->query_temp("apprentice_azi") )
	{
		message_vision("阿紫冲着$N噗嗤一乐，“乖孩子！”\n", ob);
		return 1;
	}	
	if( (ob->query_per() + ob->query_elo() + ob->query_skill("flattering",1)/5) < 60 )
	{
		message_vision("但是阿紫一本正经地说道：“磕得不够响，再磕！”\n", ob);
	}
	else    
	{
		command("say 好啦好啦,我收下你了。\n");
		command("recruit "+ob->query("id"));
	}				
	return 1;
}

void die()
{
	if( random(10) < 2 )
		new(__DIR__"obj/shengmu-wangding")->move(this_object());

	::die();
}

void init()
{

        object ob;
        mapping fam;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") >=100 && ((fam = ob->query("family")) && fam["master_id"] == "azi"))
        {
                command("say 你多次杀我同道中人，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}

void consider()
{
        object *enemy,target;
        string *allid,eff_id;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        eff_id = target->query("id");
        allid = target->query_temp("apply/id");
        if( arrayp(allid) )
        {
        	allid -= ({ 0 });
	        if( sizeof(allid) )
	                eff_id = allid[sizeof(allid)-1];	
	}
//	command("say xixi,"+eff_id);	
	command("flatter "+ eff_id );
}	