// madam.c
// written by tang

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;
                  
string ask_me();
string ask_book();
void use_poison();         
void use_dart(); 
void cui_poison();
void heal();

void create()
{
	set_name("欧阳敏", ({ "ouyang min", "ouyang", "min" }) );
	set("title",HIG"先门主夫人"NOR);
	set("nickname", CYN"五毒仙子"NOR);
	set("gender", "女性");
	set("age", 72);
	set("long","她是唐门前任门主唐博浒的夫人，乃五毒教前教主的妹妹，
五毒教现任教主的姑姑，昔年与“彩云仙子”、“火观音”、
“桃花娘子”并称江湖四大女煞星。\n");		
	set("attitude", "peaceful");
	set("class", "legend");

	set("str", 30 + random(10));
	set("cps", 30 + random(10));
	set("int", 40 + random(10));
	set("cor", 30 + random(10));
	set("con", 40 + random(10));
	set("spi", 30 + random(10));
	set("per", 20 + random(10));
	set("kar", 20 + random(10));
                                        
	set("kee",4000);
        set("max_kee", 4000);
	set("gin",1000);
        set("max_gin", 1000);
	set("sen",1000);
	set("max_sen", 1000);
	set("atman", 300);
	set("max_atman", 300);
	set("mana", 300);
	set("max_mana", 300);                   

	set("force", 4000);
	set("max_force", 4000);
	set("force_factor", 160);

	set("combat_exp", 5000000);
	set("shen_type",-1);

	set("husband/id","tang bohu");
	set("husband/name","唐博浒");

	set_skill("force", 200);
	set_skill("sword", 180);
	set_skill("throwing", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);                  
	set_skill("move", 180);          
	set_skill("strike",160);
	set_skill("literate", 200);
	set_skill("dugong", 220);

	set_skill("sunv-xinfa", 200);
	set_skill("yuenv-jian", 200);
	set_skill("tiannv-sanhua", 200);
	set_skill("tangmen-xinfa", 200);
	set_skill("tangshi-jian", 200);
	set_skill("mantian-huayu", 200);
	set_skill("taxue-wuhen", 200);
	set_skill("tangmen-duzhang",180);

	map_skill("dodge", "taxue-wuhen");              
	map_skill("move", "taxue-wuhen");
	map_skill("force", "sunv-xinfa");
	map_skill("sword", "yuenv-jian");
	map_skill("parry", "yuenv-jian");   
	map_skill("strike", "tangmen-duzhang");
	map_skill("throwing", "tiannv-sanhua");     

	prepare_skill("strike","tangmen-duzhang");

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		"唐老太太脚步轻移，右手轻扬。\n",
		"唐老太太左手一扬，从袖中发出一颗毒蒺藜。\n",
		(: use_poison :),              
		(: use_dart :),
		(: cui_poison :),
//		(: heal :),
//	 	(: perform_action , "throwing.sanhua" :)
	}) );

	create_family("唐门", 3, "先门主夫人");

	set_temp("apply/defense", 100);
	set_temp("apply/attack",50);
                                                                         
	set("biao",1);
	set("book",1);
	set("inquiry", ([
                	"回旋镖" : (: ask_me :),
                	"秘籍" : (: ask_book :),
        		]));                                                 

	setup();
	carry_object("/d/tangmen/obj/huixuanbiao")->wield();
	carry_object("/d/tangmen/obj/skirt")->wear();

}

string ask_me()
{	
	object ob;

        if ( this_player()->query("family/family_name") != "唐门")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (query("biao") < 1)
                return "你来晚了，本派的回旋镖不在此处。";
        add("biao", -1);
        ob = new("/d/tangmen/obj/huixuanbiao");
        ob->move(this_player());
        return "好吧，这枚回旋镖你拿去用吧。";
}                        

string ask_book()
{	
	object ob;

        if( this_player()->query("family/family_name") != "唐门")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
	if( this_player()->query("int") < 30 )
		return "你资质太差，给你也是浪费。\n";
        if( query("book") < 1 )
                return "你来晚了，本派的秘籍不在此处。";
        add("book", -1);
        ob = new("/d/tangmen/obj/dujing");
        ob->move(this_player());
        return "好吧，这本毒经你拿去好好研究吧。";
}                        

void heal()
{
        object ob=this_object();

        if (ob->query("kee") < ob->query("eff_kee"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("gin") < ob->query("eff_gin"))
                command("exert regenerate");

        return;
}

void use_poison()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            	{
		ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));    
		tell_object(ob, "你觉得脸上一痒，似乎有什麽东西，伸手一摸却什麽也没有。\n");
		ob->update_condition("tm_poison", random(2));    
	}
	return ;
}

void use_dart()
{
	object *enemy, ob;
	string msg;

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
            	{
		ob->set("kee", ob->query("kee")-40);    
		message_vision( "$N觉得身上一痒，伸手一摸，原来被欧阳敏的毒蒺藜打中了。\n",ob);
		ob->apply_condition("tm_poison", random(10)+ob->query_condition("tm_poison"));    
		ob->update_condition("tm_poison", random(2));    
	}
	return ;
}

void cui_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

	if( ob )	command("exert quickpoison "+ob->query("id"));

        return ;
}

void attempt_apprentice(object ob)
{
	object *usr;
	int i,n;
	string arg;

	if((string)ob->query("family/family_name") != "唐门")
	{
		command("say 我只收本门弟子，"+ RANK_D->query_respect(ob) + "可先加入唐门。\n。");
		return;
	}                                                         
	
/*
	if( this_player()->query("gender") == "无性" )
	{
		command("say 本门不收太监，这位公公请回。\n。");
		return;	
	}
*/

	if (ob->query_skill("dugong",1) < 120)
	{
		command("say 你的毒功还不够精熟，是不是需要再努力一点。\n");
		return ;
	}

	usr = users();
	i = sizeof(usr);

	while( i-- )
	{
		if( !(wizardp(usr[i])) && 
			usr[i]->query("family/master_id") == this_object()->query("id") )
			n ++;
	}

	if( n > 4 )
	{
		tell_object(ob,"我现在不想再收徒啦，你走吧。\n");
		return ;
	}	

	ob->set_temp("apprentice_ouyang",1);

	arg = ob->name();

	if( arg[0..1] != "唐" )
		tell_object(ob,"我唐门武功不传外姓，你要改姓唐，我才能收你。\n");
	tell_object(ob,"如果你发誓效忠唐门的话，就可以拜我为师。\n");
	return ;
}

void init()
{
	object me;
	int i;

	me = this_player();
	i = 80 - me->query_skill("dugong",1);
	if( userp(me) && i > 0 )
	{
		me->apply_condition("tm_poison", random(i)/10+1
			+me->query_condition("tm_poison"));
		tell_object(me,"你中了"+HIG"唐门无影毒。\n"NOR);
	}

	add_action("do_swear","swear");
	add_action("give_quest","quest");
}

int do_swear(string arg)
{
	string cname;
	object me;

	me = this_player();

	if( !(me->query_temp("apprentice_ouyang")) )	return 0;

	if( !arg || arg != "效忠唐门" )
	{
		tell_object(me,"你絮絮叨叨的在念什么？\n");
		return 1;
	}
		
	me->delete_temp("apprentice_ouyang");

	command("say 好吧，我就收下你了。");
	command("recruit " + me->query("id"));

	cname = me->name();
	if( sizeof(cname) > 2 )
		me->set("name","唐"+cname[2..sizeof(cname)-1]);
	else
		me->set("name","唐"+cname);
	this_player()->set("class", "legend");
	if( this_player()->query("gender") == "女性" )
		this_player()->set("title",HIR "唐门" NOR + GRN +"四代女弟子" NOR);
	else 	this_player()->set("title",HIR "唐门" NOR + GRN +"四代弟子" NOR);
	return 1;
}
