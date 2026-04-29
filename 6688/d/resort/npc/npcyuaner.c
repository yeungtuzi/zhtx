#include <ansi.h>

inherit NPC;
//inherit F_MASTER;
inherit F_QUEST;

void create()
{
	set_name(HIG"媛儿"NOR, ({"yuan er","yuan","er"}));
	set("nickname", HIY"花伴丽人行"NOR);
	set("long", 
	HIG"媛儿是雪蕊的得意弟子，聪明好学，\n媛儿一帆风顺地学完了铁雪山庄的武功，\n在心爱的人及众多好友相继淡出江湖后，她也悄然归隐。\n"NOR);
	set("title", HIC "铁雪乖乖女" NOR);
	set("gender", "女性");
	set("age", 18);
	set("rank_info/respect", "乖乖女");
        create_family("铁雪山庄", 2, "弟子");

        set("combat_exp",1500000);

	set("max_kee", 3000);
	set("max_gin", 1000);
	set("max_sen",1000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("attitude", "friendly");

	set("per", 30);
	set("cps", 48);
	set("cor", 30);

	set_skill("force", 200);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("strike", 180);
	set_skill("qimen-bagua", 71);
	set_skill("unarmed", 151);
	set_skill("literate", 201);

	set_skill("deisword",200);
	set_skill("meihua-shou",200);
	set_skill("qidaoforce",200);
	set_skill("fall-steps",200);

	map_skill("dodge", "fall-steps");
	map_skill("strike","meihua-shou");
	map_skill("move","fall-steps");
	map_skill("force", "qidaoforce");
	map_skill("parry", "deisword");
	map_skill("sword", "deisword");
	
	prepare_skill("strike","meihua-shou");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 80);

	set("chat_chance_combat", 20);  
	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

	setup();
	carry_object(__DIR__"obj/thin_sword")->wield();
	carry_object(__DIR__"obj/yuanerbelt")->wear();
}

void init()
{       
	object ob;
	ob = this_player();
	::init();
	call_out("greeting", 1, ob);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(!userp(ob)) return;
	if( ob->query("env/invisibility") ) ob->delete("env/invisibility");
	if( ob->query("env/immortal") ) ob->delete("env/immortal");

	message_vision(	"\n$N对$n盈盈道了个万福。\n",this_object(),ob );

 	if(ob->query("id")=="yeung")
	{	
                command("jump yeung");
	}
	else if(ob->query("id")=="yuaner")
	{	
                command("sister yuaner");
		say("呀，主人回来啦。\n");
	}
	else if(ob->query("id")=="voodoo")
	{	
                command("touch voodoo");
		say("媛儿雪白的脸庞上虽然尽是笑意，眼圈却不由自主地红了：公子，你终于回来了。。。\n");
	}
	else if( ob->query("family/family_name") == "铁雪山庄" )
	{
		if( ob->query("gender") == "男性" )
			message_vision(	"$N向$n笑道：师弟好啊。\n",this_object(),ob );		
		else if( ob->query("gender") == "女性" )
			message_vision(	"$N向$n笑道：小师妹好啊。\n",this_object(),ob );		
		else
		{
			command("kok "+ ob->query("id"));
			message_vision(	"$N顿足道：想不到我们铁雪山庄也出了这种无耻之徒啊。\n",this_object(),ob );				
			command("hit "+ ob->query("id"));
		}
	}
	say("\n");
}

void die()
{
	object ob;
        if( objectp(ob = query_temp("last_damage_from")) )
	{
		command("chat " + HIR + ob->query("name") + "你这" + RANK_D->query_rude(ob) + "，铁雪的师弟师妹们要给我报仇啊！！！\n"NOR);
		tell_object(ob,HIR"你死定了！！！\n"NOR);
	}
	::die();
}

int accept_fight(object who)
{
	command("nomatch "+who->query("id"));
	return 0;
}

void killed_enemy(object victim)
{
	command("chat 怎么偏偏有这么多不知死活的家伙呀？");
	command("chat " + victim->query("name") + "你这" + RANK_D->query_rude(victim) + "，给本姑娘死去吧！\n"NOR);
}
void attempt_apprentice(object ob)
{
	command("say 有师傅在，我还不能收弟子。");
/*        
	if( (string)ob->query("family/family_name") != "铁雪山庄" || (string)ob->query("gender") != "女性" )
	{
		command("say 我只收本派女弟子，你还是去拜庄主吧！");	
	}
        else {

                command("smile");
                command("say 你日后必有大成！");
                command("smile");
                command("recruit " + ob->query("id") );
	}
*/
}

// check if bribe is valid
int valid_bribe(object who,int val) {
        message_vision( (this_object())->query("name")+"向$N一摇头，说道： 给我钱干什么？！\n",who);
        return(0);
}

// called when not finish the task
int quest_punish(object who) {
        message_vision( (this_object())->query("name")+"向$N叹了口气，说道： 你好好学学功夫再要任务吧！\n" ,who);
    who->set("quest",0);
    return(0);
}
